#include "shell.h"

/**
 * exit_str_arg - Checks argument passed to exit
 * @str: Argument
 * @av: command line arguments
 *
 * Return: void
 */
void exit_str_arg(char *str, char **av)
{
	write(1, av[0], strlen(av[0]));
	write(1, ": 1", 3);
	write(1, ": exit: Illegal number: ", 24);
	write(1, str, strlen(str));
	_print_char('\n');
}
