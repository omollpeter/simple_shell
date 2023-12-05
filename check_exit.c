#include "shell.h"

/**
 * check_exit_arg - Checks argument passed to exit
 * @str: Argument
 *
 * Return: void
 */
void check_exit_arg(char *str, char **av)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			write(1, av[0], strlen(av[0]));
			write(1, ": exit: ", 8);
			write(1, str, strlen(str));
			write(1, ": numeric argument required\n", 28);
			exit(2);
		}
	}
	exit(atoi(str));
}
