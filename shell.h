#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 64
#define MAX_PATH_LEN 1024

char* get_full_path(char* cmd);
void execute_run(char **arr);

#endif 
