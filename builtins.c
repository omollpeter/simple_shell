#include "shell.h"

/**
 * check_bltn - Checks if a command is a builtin
 * @cmd: Command to check
 *
 * Return: 1 if builtin, 0 otherwise
 */
int check_bltn(char *cmd)
{
	char *builtins[] = {"exit", "env", "cd", NULL};
	int i = 0;

	while (builtins[i])
	{
		if (strcmp(builtins[i], cmd) == 0)
		return (1);
		i++;
	}
	return (0);
}

/**
 * execute_bltn - Executes builtin commands
 * @argv: Array containing commands 0 or more arguments
 * @av: Program parameters
 * @env: Environment variables
 *
 * Return: void
 */
int execute_bltn(char **argv, char **av, char **env)
{
	int code;

	if (strcmp(argv[0], "exit") == 0 && argv[1] != NULL)
	{
		int i = 0, not_int = 0;

		for (i = 0; argv[1][i]; i++)
		{
			if (argv[1][i] < 48 || argv[1][i] > 57)
				not_int++;
		}
		if (not_int)
		{
			exit_str_arg(argv[1], av);
			free_array_str(argv);
		}
		else
		{
			code = atoi(argv[1]);
			free_array_str(argv);
			exit(code);
		}
	}
	else if (strcmp(argv[0], "exit") == 0)
	{
		free_array_str(argv);
		exit(0);
	}
	else if (strcmp(argv[0], "env") == 0 && argv[1] == NULL)
	{
		free_array_str(argv);
		return (list_env_vars(env));
	}
	return (-1);
}
