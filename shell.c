#include "shell.h"

/**
 * main - Checks code
 * @ac: argument count
 * @av: program parameters
 * @env: array of environment variables
 *
 * Return: 0 (Success)
 */
int main(int __attribute__((unused))ac, char **av, char **env)
{
	char *str, **argv, buffer[256], *path, *path_dirs;
	int found;

	while (isatty(0))
	{
		str = prompt();
		while (strlen(str) == 1 && str[0] == '\n')
			str = prompt();

		argv = parser(str, " \n");
		if (strcmp(argv[0], "exit") == 0 && argv[1] != NULL)
			check_exit_arg(argv[1], av);
		else if (strcmp(argv[0], "exit") == 0)
			exit(0);
		else if (strcmp(argv[0], "env") == 0 && argv[1] == NULL)
			list_env_vars(env);
		else
		{
			found = file_status(argv[0]);
			if (found == 0)
				executor(argv[0], argv, av);
			else
			{
				path_dirs = _getenv("PATH", env);
				path = path_to_exec(path_dirs, argv[0]);
				executor(path, argv, av);
			}
		}
	}


	while (fgets(buffer, 255, stdin) != NULL)
	{
		argv = parser(buffer, " \n");
	}

	return (0);
}
