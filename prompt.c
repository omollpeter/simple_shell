#include "shell.h"

/**
 * prompt - Displays shell prompt
 *
 * Return: pointer to the command to be executed, NULL otherwise
 */
char *prompt(void)
{
	char buff[512], *str;

	write(1, "($) ", 4);

	if (fgets(buff, 511, stdin) != NULL)
	{
		str = malloc(sizeof(char) * (strlen(buff) + 1));
		if (!str)
			exit(0);
		strcpy(str, buff);
		return (str);
	}

	_print_char('\n');
	exit(0);
}
