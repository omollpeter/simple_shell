#include "shell.h"

/**
 * run_cmd - Combines prompt, parser and executor
 * @str_cmd: String containing command with 0 or more arguments to execute
 * @av: Program parameters
 * @env: Environment variables
 * @mode: 1 for interactive, 0 for non-interactive
 *
 * Return: 0 on success, -1 othewise
 */
int run_cmd(char *str_cmd, char **av, char **env, int mode)
{
	char **argv, *path, *path_dirs;
	int found, result;

	argv = parser(str_cmd, " ");
	if (mode == 1)
		free(str_cmd);
	if (!argv[0])
	{
		free(argv);
		return (0);
	}
	else if (check_bltn(argv[0]))
	{
		result = execute_bltn(argv, av, env);
		return (result);
	}
	else
	{
		found = file_status(argv[0]);
		if (found == 0)
		{
			if (access(argv[0], X_OK) == 0)
				result =  (executor(argv[0], argv, env));
			else
			{
				write(2, av[0], strlen(av[0]));
				write(2, ": 1: ", 5);
				write(2, argv[0], strlen(argv[0]));
				write(2, ": Permission denied\n", 20);
				result = -1;
			}
		}
		else
		{
			path_dirs = _getenv("PATH", env);
			path = path_to_exec(path_dirs, argv[0]);
			if (!path)
			{
				write(2, av[0], strlen(av[0]));
				write(2, ": 1: ", 5);
				write(2, argv[0], strlen(argv[0]));
				write(2, ": not found\n", 12);
				result = -1;
			}
			else
			{
				result = (executor(path, argv, env));
				free(path);
			}
		}
	}
	free_array_str(argv);
	return (result);
}

/**
 * run_chain_cmds - Checks if a command is chained or not then runs it
 * @str: Command that is checked
 * @av: Program parameters
 * @env: Environment variables
 * @mode: Interactive or non-interactive
 *
 * Return: void
 */
void run_chain_cmds(char *str, char **av, char **env, int mode)
{
	int i;

	if (check_semi_colon(str))
	{
		char **arr_cmds = parser(str, ";");

		if (mode)
			free(str);
		i = 0;
		while (arr_cmds[i])
		{
			if (strcmp(arr_cmds[i], "exit") == 0)
			{
				while (arr_cmds[i])
				{
					free(arr_cmds[i]);
					i++;
				}
				free(arr_cmds);
				exit(0);
			}
			run_cmd(arr_cmds[i], av, env, mode);
			i++;
		}
		free(arr_cmds);
	}
	else
		run_cmd(str, av, env, mode);
}
