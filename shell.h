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

char *prompt(void);
char **parser(char *str, char *delim);
size_t token_count(char *str, char *delim);
void execute(char **argv);

#endif /* SIMPLE_SHELL_H */
