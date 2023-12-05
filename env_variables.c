#include "shell.h"
/**
 * list_env_vars - lists all the environment variables
 * @env: array of enviroment variables
 *
 * Return: Void
 */
void list_env_vars(char **env)
{
	int i = 0;

	while (env[i])
	{
		write(1, env[i], strlen(env[i]));
		_print_char('\n');
		i++;
	}
}
