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
void exit_str_arg(char *str, char **av);
int list_env_vars(char **env);
char *prompt(void);
char **parser(char *str, char *delim);
size_t token_count(char *str, char *delim);
int executor(char *exec, char **argv, char **av);
char *_getenv(char *name, char **env);
char *path_to_exec(char *path_dirs, char *exec);
int file_status(char *command);
void free_array_str(char **str);
void free_array_str_2(char **str);
char **create_arr(char *str);
int check_delim(char *str, char *delim);
int check_bltn(char *cmd);
int execute_bltn(char **argv, char **av, char **env);
int run_cmd(char *str_cmd, char **av, char **env, int mode);
int check_semi_colon(char *str);
int check_hash(char *str);
int ch_dir(char *path, char **env);
char **_sentenv(char **env, char *name, char *value, int overwrite);
int env_position(char *name, char **env);
void run_chain_cmds(char *str, char **av, char **env, int mode);
void interactive_mode(char **av, char **env, int mode);
void non_interactive_mode(char **av, char **env, int mode);

#endif /* SIMPLE_SHELL_H */
