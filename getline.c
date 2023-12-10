#include "shell.h"

/**
 * display_prompt - Displays a prompt which allows user to insert an input
 *
 * Return: void
 */
char *display_prompt(void)
{
	char *buffer = malloc(1024);
	ssize_t bytesRead;
	pid_t pid;


	pid = fork();
	if (pid == 0)
	{
		printf("($) ");
		exit(0);
	}
	else
	{
		while ((bytesRead = read(0, buffer, 1023)) != -1)
		{
			return (buffer);
		}
		return (NULL);
	}
}
