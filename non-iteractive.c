#include "shell.h"

/**
 * non_interactive_mode - Executes when the shell is in non-interactive mode
 * @av: Program parameters
 * @env: Environment variables
 * @mode: Mode of interaction (1)
 *
 * Return: void
 */
void non_interactive_mode(char **av, char **env, int mode)
{
	char buffer[256];
	int len;

	while (fgets(buffer, 255, stdin) != NULL)
	{
		len = (int) strlen(buffer);
		if (buffer[0] == '\n')
			continue;
		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		run_chain_cmds(buffer, av, env, mode);
	}
}
