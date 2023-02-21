#include "shell.h"
/**
 * execute_run - handles commands with command
 * @arr: recieves arr
 * Return: 1,0,-1
 */
void execute_run(char **arr)
{
	char *cmd = arr[0];
	char cmd_path[MAX_PATH_LEN];

	if (strchr(cmd, '/') != NULL)
	{
		snprintf(cmd_path, MAX_PATH_LEN, "%s", cmd);
	}
	else
	{
		char *full_path = get_full_path(cmd);

		if (full_path == NULL)
		{
			fprintf(stderr, "Command not found: %s\n", cmd);
			return;
		}
		snprintf(cmd_path, MAX_PATH_LEN, "%s", full_path);
		free(full_path);
	}
	pid_t my_pid;
	int status;

	my_pid = fork();

	if (my_pid == -1)
	{
		perror("Error");
		return;
	}
	else if (my_pid == 0)
	{
		if (execvp(cmd_path, arr) == -1)
		{
			perror(cmd_path);
			exit(1);
		}
	}
	else
		wait(&status);
}
