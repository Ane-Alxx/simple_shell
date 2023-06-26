#include "shell.h"
/**
* _get_pathsub - the function for getting the path
* @env: omo the enviro
* Return: some value, success
*/

char *_get_pathsub(char **env)
{
	size_t k = 0, c = 0, x = 5;
	char *p = NULL;

	for (k = 0; _strncmp(env[k], "PATH=", 5); k++)
		;
	if (env[k] == NULL)
		return (NULL);

	for (x = 5; env[k][c]; c++, x++)
		;
	p = malloc(sizeof(char) * (x + 1));

	if (p == NULL)
		return (NULL);

	for (c = 5, x = 0; env[k][c]; c++, x++)
		p[x] = env[k][c];

	p[x] = '\0';
	return (p);
}
