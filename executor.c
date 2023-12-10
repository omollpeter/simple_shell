#include "shell.h"

/**
 * executor - Executes the given command
 * @argv: Command table
 * @av: program parameters
 * @exec: Path to the executable file
 *
 * Return: 0 on success, -1 otherwise
 */
int executor(char *exec, char **argv, char **av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed\n");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(exec, argv, NULL) == -1)
		{
			perror(av[0]);
			return (-1);
		}
	}
	else
	{
		wait(&status);
		return (0);
	}
	return (-1);
}
