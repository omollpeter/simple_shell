#include "shell.h"

/**
 * executor - Executes the given command
 * @argv: Command table
 * @env: enviroment variables
 * @exec: Path to the executable file
 *
 * Return: 0 on success, -1 otherwise
 */
int executor(char *exec, char **argv, char **env)
{
	pid_t pid;
	int status, result = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed\n");
		result = -1;
	}
	if (pid == 0)
	{
		result = execve(exec, argv, env);
	}
	else
	{
		wait(&status);
	}
	return (result);
}
