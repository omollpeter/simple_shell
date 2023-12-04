#include "shell"

/**
 * prompt - Displays shell prompt
 *
 * Return: pointer to the command to be executed, NULL otherwise
 */
char *prompt(void)
{
	char *buff = NULL;
	ssize_t n = 0;

	write(1, "($) ", 4);

	while (getline(&buff, &n, stdin) != -1)
		return (buff);

	perror("getline\n");
	return (NULL);
}
