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
	int i = 0, j = 0, eq_sn;
	size_t len = strlen(name);
	char *key, *value, **arr_str;

	key = malloc(sizeof(char) * (len + 1));
	if (!key)
		return (NULL);

	while (env[i])
	{
		eq_sn = (int) len;
		if (strlen(env[i]) > len && env[i][eq_sn] == 61)
		{
			for (j = 0; j < (int) len; j++)
				key[j] = env[i][j];
			key[j] = '\0';

			if (strcmp(name, key) == 0)
			{
				arr_str = parser(env[i], "=");
				value = malloc(sizeof(char) * (strlen(arr_str[1]) + 1));
				if (!value)
					return (NULL);
				strcpy(value, arr_str[1]);
				free_array_str(arr_str);
				free(key);
				return (value);
			}
		}
		i++;
	}
	free(key);
	return (NULL);
}
