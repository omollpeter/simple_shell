#include "shell.h"

/**
 * check_semi_colon - Checks if commands have been chained with ;
 * @str: 1 or chained commands
 *
 * Return: Number of ;
 */
int check_semi_colon(char *str)
{
	int i = 0, colon = 0;

	while (str[i])
	{
		if (str[i] == ';')
			colon++;
		i++;
	}
	return (colon);
}
