#include "shell.h"
/**
* _val_pathsub - function for val pathsub
* @arg: argument to do
* @env: the environment
* Return: pointerere
*/
int _val_pathsub(char **arg, char **env)
{
	char *toke = NULL, *pathr = NULL, *patha = NULL;
	size_t val_path, lenny;
	struct stat status_ptr;

	if (stat(*arg, &status_ptr) == 0)
		return (-1);
	pathr = _get_pathsub(env);
	if (!pathr)
		return (-1);
	toke = strtok(pathr, ":");
	lenny = _strlen(*arg);
	while (toke)
	{
		val_path = _strlen(toke);
		patha = malloc(sizeof(char) * (val_path + lenny + 2));
		if (!patha)
		{
			free(pathr);
			return (-1);
		}
		patha = strcpy(patha, toke);
		_strcat(patha, "/");
		_strcat(patha, *arg);

		if (stat(patha, &status_ptr) == 0)
		{
			*arg = patha;
			free(pathr);
			return (0);
		}
		free(patha);
		toke = strtok(NULL, ":");
	}
	toke = '\0';
	free(pathr);
	return (-1);
}
