#include "shell.h"

/**
 * path_to_exec - Searches for executable in PATH directories
 * @path_dirs: String with colon delimited list of directories
 * @exec: Executable file to be searched
 *
 * Return: pointer to string containing path to executable
 */
char *path_to_exec(char *path_dirs, char *exec)
{
	char *path, **arr_path_dirs;
	int i = 0;
	DIR *dp;
	size_t len1, len2;

	arr_path_dirs = parser(path_dirs, ":");
	free(path_dirs);
	while (arr_path_dirs[i])
	{
		struct dirent *dir;

		dp = opendir(arr_path_dirs[i]);
		if (!dp)
		{
			closedir(dp);
			free_array_str(arr_path_dirs);
			return (NULL);
		}
		while ((dir = readdir(dp)) != NULL)
		{
			if (strcmp(dir->d_name, exec) == 0)
			{
				len1 = strlen(arr_path_dirs[i]);
				len2 = strlen(exec);
				path = malloc(sizeof(char) * (len1 + len2 + 2));
				if (!path)
					return (NULL);
				strcpy(path, arr_path_dirs[i]);
				strcat(path, "/");
				strcat(path, exec);
				closedir(dp);
				free_array_str(arr_path_dirs);
				return (path);
			}
		}
		closedir(dp);
		i++;
	}
	free_array_str(arr_path_dirs);
	return (NULL);
}
