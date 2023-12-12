#include "shell.h"

/**
 * check_semi_colon - Checks if commands have been chained with ;
 * @str: 1 or chained commands (string)
 *
 * Return: 1 if ; present, 0 othewise
 */
int check_semi_colon(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == ';')
			return (1);
		i++;
	}
	return (0);
}

/**
 * check_hash - Checks if commands have been chained with ;
 * @str: String with or without hash
 *
 * Return: 1 if hash is found, 0 otherwise
 */
int check_hash(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] == '#')
			return (1);
		i++;
	}
	return (0);
}