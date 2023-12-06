#include "shell.h"

/**
 * file_status - checks if the given command path is available
 * @command: program to execute
 *
 * Return: 0 if path is found, -1 otherwise
 */
int file_status(char *command)
{
	struct stat st;

	if (stat(command, &st) == 0)
		return (0);
	else
		return (-1);
}
