#include "shell.h"

/**
 * main - Checks code
 *
 * Return: 0 (Success)
 */
int main(int __attribute__((unused))ac, char __attribute__((unused))**av, char __attribute__((unused))**env)
{
	char *str, **argv;

	while (isatty(0))
	{
		str = prompt();
		while (strlen(str) == 1 && str[0] == '\n')
			str = prompt();

		argv = parser(str, " \n");
		executor(argv);
	}

	return (0);
}
