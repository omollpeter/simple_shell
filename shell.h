#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <dirent.h>

int _print_char(char c);
void check_exit_arg(char *str, char **av);
void list_env_vars(char **env);
char *prompt(void);
char **parser(char *str, char *delim);
size_t token_count(char *str, char *delim);
void executor(char *exec, char **argv, char **av);
char *_getenv(char *name, char **env);
char *path_to_exec(char *path_dirs, char *exec);
int file_status(char *command);

#endif /* SIMPLE_SHELL_H */
