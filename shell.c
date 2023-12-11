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
	char *str, buffer[256];
	int len, i, mode = 0;

	while (isatty(0))
	{
		mode = 1;
		str = prompt();
		while (strlen(str) == 1 && str[0] == '\n')
		{
			char *temp_str = str;

			free(temp_str);
			str = prompt();
		}
		len = (int) strlen(str);

		str[len - 1] = '\0';
		if (check_semi_colon(str))
		{
			char **arr_cmds = parser(str, ";");

			free(str);
			i = 0;

			while (arr_cmds[i])
			{
				run_cmd(arr_cmds[i], av, env, mode);
				i++;
			}
		}
		else
			run_cmd(str, av, env, mode);
	}

	while (fgets(buffer, 255, stdin) != NULL)
	{
		len = (int) strlen(buffer);

		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		run_cmd(buffer, av, env, mode);
	}
	return (0);
}
