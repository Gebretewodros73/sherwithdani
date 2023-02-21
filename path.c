#include "shell.h"
/**
 * get_full_path - get a full path
 * @cmd: recieve comand
 * Return: NULL and full_path
 */

char *get_full_path(char *cmd)
{
	char *path_env = getenv("PATH");
	char *path = strtok(path_env, ":");
	char cmd_path[MAX_PATH_LEN];

	while (path)
	{
		snprintf(cmd_path, MAX_PATH_LEN, "%s/%s", path, cmd);
		if (access(cmd_path, X_OK) == 0)
		{
			char *full_path = strdup(cmd_path);

			return (full_path);
		}
		path = strtok(NULL, ":");
	}
	return (NULL);
}
