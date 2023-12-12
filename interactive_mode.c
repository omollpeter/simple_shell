#include "shell.h"

/**
 * interactive_mode - Executes when the shell is in interactive mode
 * @av: Program parameters
 * @env: Environment variables
 * @mode: Mode of interaction (1)
 *
 * Return: void
 */
void interactive_mode(char **av, char **env, int mode)
{
	char *str;
	int len;

	str = prompt();
	while (strlen(str) == 1 && str[0] == '\n')
	{
		char *temp_str = str;

		free(temp_str);
		str = prompt();
	}

	len = (int) strlen(str);
	str[len - 1] = '\0';
	if (str[0] == '#')
		free(str);
	else if (check_hash(str))
	{
		char **hash_in_cmd = parser(str, "#");

		free(str);
		run_chain_cmds(hash_in_cmd[0], av, env, mode);
		free_array_str_2(hash_in_cmd);
	}
	else
		run_chain_cmds(str, av, env, mode);
}
