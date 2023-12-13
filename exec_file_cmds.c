#include "shell.h"

/**
 * exec_cmds_in_file - Executes commands present in the given file
 * @av: Program parameters
 * @env: Environment variables
 * @mode: Mode of interaction (0)
 *
 * Return: 0 if file exist and has zero or more commands
 */
int exec_cmds_in_file(char **av, char **env, int mode)
{
	char buffer[1024];
	FILE *fp;
	int len;

	fp = fopen(av[1], "r");
	if (!fp)
	{
		printf("%s does not exist\n", av[1]);
		exit(2);
	}
	while (fgets(buffer, 255, fp) != NULL)
	{
		len = (int) strlen(buffer);
		if (buffer[0] == '\n')
			continue;
		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		run_chain_cmds(buffer, av, env, mode);
	}
	fclose(fp);
	return (0);
}
