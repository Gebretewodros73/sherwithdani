#include "shell.h"
#define MAX_CMD_LEN 1024
/**
 * main - perform the task
 * @argc: counts arg
 * @argv: storse arg
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *command = NULL, *stkn;
	size_t len = 0;

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
			i++; }
		arr[i] = NULL;
		if (arr[0] == NULL)
		{
			free(arr);
			continue;
		}
		if (strcmp(arr[0], "exit") == 0 && (arr[1] == NULL))
		{
			printf("Exiting shell...\n");
			exit(0);
		}
		else if (strcmp(arr[0], "env") == 0 && (arr[1] == NULL))
		{
			print_environment();
		}
		else
		{
			execute_run(arr);
		}
		free(arr); }
	free(command);
	return (0);
}
