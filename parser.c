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
	char *str_copy, *token;
	size_t count = 0;

	if (str == NULL || delim == NULL)
	{
		perror("NULL string\n");
		return (0);
	}

	str_copy = malloc(sizeof(char) * (strlen(str) + 1));
	if (!str_copy)
	{
		perror("Malloc failed\n");
		return (0);
	}
	strcpy(str_copy, str);
	token = strtok(str_copy, delim);
	while (token)
	{
		count++;
		token = strtok(NULL, delim);
	}
	free(str_copy);
	return (count + 1);
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
	char **str_tokens, *str_copy, *token;
	size_t count;
	int i = 0;

	if (str == NULL || delim == NULL)
	{
		perror("NULL string\n");
		return (NULL);
	}
	count = token_count(str, delim);
	str_tokens = malloc(sizeof(char *) * count);
	if (!str_tokens)
	{
		perror("Malloc failed\n");
		return (NULL);
	}
	str_copy = malloc(sizeof(char) * (strlen(str) + 1));
	if (!str_copy)
	{
		perror("Malloc failed\n");
		return (NULL);
	}
	strcpy(str_copy, str);
	token = strtok(str_copy, delim);
	while (token)
	{
		str_tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!str_tokens[i])
		{
			perror("Malloc failed\n");
			return (NULL);
		}
		strcpy(str_tokens[i], token);
		i++;
		token = strtok(NULL, delim);
	}
	str_tokens[i] = NULL;
	free(str_copy);
	return (str_tokens);
}
