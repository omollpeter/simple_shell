#include "shell.h"

/**
 * _getenv - Fetches a value to env. variable from the array of env variables
 * @name: Key
 * @env: Array of environment variables
 *
 * Return: pointer to the value, NULL otherwise
 */
char *_getenv(char *name, char **env)
{
	char *token;
	int i = 0;

	while (env[i])
	{
		token = strtok(env[i], "=");
		if (strcmp(token, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}

	return (NULL);
}
