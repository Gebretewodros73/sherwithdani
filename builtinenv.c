#include "shell.h"
/**
 * print_environment - builtin environ
 * Return: void
 */

void print_environment(void)
{
	char **environ;
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
