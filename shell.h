#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

#define MAX_ARGS 64
#define MAX_PATH_LEN 1024

char *get_full_path(char *cmd);
void execute_run(char **arr);
void print_environment(void);

#endif
