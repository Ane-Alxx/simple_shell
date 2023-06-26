#include "shell.h"


/**
* _getenv - function definition for getenv
* @env: enviroment
*/

void _getenv(char **env)
{
	size_t t = 0;

	while (env[t])
	{
		write(STDOUT_FILENO, env[t], _strlen(env[t]));
		write(STDOUT_FILENO, "\n", 1);
		t++;
	}
}
