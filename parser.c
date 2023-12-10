#include "shell.h"


/**
 * token_count - counts all arguments from the prompt
 * @str: string input
 * @delim: delimeter
 *
 * Return: number of argunemts from the prompt
 */
size_t token_count(char *str, char *delim)
{
	size_t count = 0;
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] != delim[0])
		{
			count++;
			i++;
			continue;
		}
		if (str[i] == delim[0] && str[i + 1] != delim[0])
		{
			if (str[i + 1] != '\0')
				count++;
		}
		else if ((str[i] == delim[0] && str[i + 1] == delim[0]))
		{
			i++;
			continue;
		}

		i++;
	}
	return (count);

}

/**
 * parser - tokenizes the string input
 * @str: string input
 * @delim: delimeter
 *
 * Return: pointer to tokens
 */
char **parser(char *str, char *delim)
{
	char **str_tokens;
	int i = 0, start = 0, j = 0;
	size_t count = token_count(str, delim);

	str_tokens = malloc(sizeof(char *) * (count + 1));
	while (str[i])
	{
		if (i == 0 && str[i] == delim[0])
		{
			str = str + 1;
			i = 0;
			continue;
		}
		if (str[i] == delim[0] && i > 0)
		{
			str_tokens[j] = malloc(sizeof(char) * (i + 1));
			while (start < i)
			{
				str_tokens[j][start] = str[start];
				start++;
			}
			str_tokens[j][start] = '\0';
			j++;
			start = 0;
			str = str + i + 1;
			i = 0;
			continue;
		}
		if (str[i] != delim[0] && str[i + 1] == '\0')
		{
			str_tokens[j] = malloc(sizeof(char) * (i + 2));
			while (start < i + 1)
			{
				str_tokens[j][start] = str[start];
				start++;
			}
			str_tokens[j][start] = '\0', j++;
			break;
		}
		i++;
	}
	str_tokens[j] = NULL;
	return (str_tokens);
}
