#include "shell.h"

/**
 * main - Checks code
 *
 * Return: 0 (Success)
 */
int main(int __attribute__((unused))ac, char **av, char __attribute__((unused))**env)
{
	char *str, **argv;

	while (isatty(0))
	{
		str = prompt();
		while (strlen(str) == 1 && str[0] == '\n')
			str = prompt();

		argv = parser(str, " \n");
		if (strcmp(argv[0], "exit") == 0 && argv[1] != NULL)
			check_exit_arg(argv[1], av);
		if (strcmp(argv[0], "exit") == 0)
			exit(0);
		executor(argv, av);
	}

	return (0);
}
