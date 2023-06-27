#include "shell.h"

/**
* _getpathsub - well lets get the p
* @env: my enviro
* Return: the path
*/

char *_getpathsub(char **env)
{
	size_t k = 0, b = 0, x = 5;
	char *zpath = NULL;

	for (k = 0; _strncmp(env[k], "PATH=", 5); k++)
		;
	if (env[k] == NULL)
		return (NULL);

	for (x = 5; env[k][b]; b++, x++)
		;
	zpath = malloc(sizeof(char) * (x + 1));

	if (zpath == NULL)
		return (NULL);

	for (b = 5, x = 0; env[k][b]; b++, x++)
		zpath[x] = env[k][b];

	zpath[x] = '\0';
	return (zpath);
}
