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
	int mode = 0;

	while (isatty(0))
	{
		mode = 1;
		interactive_mode(av, env, mode);
	}

	non_interactive_mode(av, env, mode);
	return (0);
}
