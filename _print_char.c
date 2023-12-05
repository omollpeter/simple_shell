#include "shell.h"

/**
 * _print_char - prints a character
 * @c: character to be printed
 *
 * Return: 1 on success, -1 otherwise
 */
int _print_char(char c)
{
	return (write(1, &c, 1));
}
