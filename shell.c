#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_CMD_LEN 1024


extern char **environ;

void print_environment();
int main(int argc, char **argv)
{
    char *command = NULL;
    size_t len = 0;
    char *stkn;

    while (1)
    {
        printf("$ ");
        getline(&command, &len, stdin);

        stkn = strtok(command, " \n");

        char **arr = malloc(sizeof(char *) * (MAX_ARGS + 1));
        arr[0] = stkn;

        int i = 1;
        while (stkn != NULL)
        {
            stkn = strtok(NULL, " \n");
            arr[i] = stkn;
            i++;
        }
        arr[i] = NULL;

        if (arr[0] == NULL) {
            free(arr);
            continue;
        }

        if (strcmp(arr[0], "exit") == 0) {
    printf("Exiting shell...\n");
    exit(0);
} else if (strcmp(arr[0], "env") == 0) {
    print_environment();
} else {
    execute_run(arr);
}

        free(arr);
    }

    free(command);
    return (0);
}

void print_environment() {
    char **env = environ;
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}
