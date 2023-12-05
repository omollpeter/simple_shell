#include "shell.h"

/**
 * executor - Executes the given command
 * @argv: Command table
 * @av: program parameters
 *
 * Return: void
 */
void executor(char **argv, char **av)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed\n");
		exit(98);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror(av[0]);
			exit(98);
		}
	}
	else
		wait(&status);
}
