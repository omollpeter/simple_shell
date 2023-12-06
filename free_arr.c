#include "shell.h"

/**
 * free_array_str - Frees space allocated to array of pointers
 * @str: Array of pointers to free
 *
 * Return: void
 */
void free_array_str(char **str)
{
	int i = 0;

	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
