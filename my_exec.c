#include "shell.h"

int sh_exitsub(char **argu);
int sh_ctrlsub(char **argu);
int sh_cdsub(char **argu);
int sh_helpsub(char **argu);


char *prefabs[] = {"cd", "help", "exit", "^D"};

int (*prefab_sub[]) (char **) = {&sh_cdsub, &sh_helpsub, &sh_exitsub, &sh_ctrlsub};

/**
* sh_numprefab - function to get length
* Return: length
*/

int sh_numprefab(void)
{
	return (sizeof(prefabs) / sizeof(char *));
}


/**
* sh_cdsub - function to change directories
* @argu: arguments to pass
* Return: 1 on success
*/
int sh_cdsub(char **argu)
{
	if (argu[1] == NULL)
	{
		fprintf(stderr, "shell: expected argument to change\"cd\"\n");
	}
	else
	{
		if (chdir(argu[1]) != 0)
		{
			perror("shell_says");
		}
	}
	return (1);
}

/**
* sh_helpsub - display help info
* @argu: arguments stuff
* Return: 1, success
*/
int sh_helpsub(char **argu)
{
	int k;

	printf("Help Guide\n");
	printf("there is a whole manual you can read for help\n");
	(void)argu;
	for (k = 0; k < sh_numprefab(); k++)
	{
		printf("  %s\n", prefabs[k]);
	}

	return (1);
}

/**
* sh_exitsub - we leave this all behind
* @argu: Arguments list
* Return: 0 on success
*/
int sh_exitsub(char **argu)
{
	(void)argu;
	free(argu);
	return (200);
}

/**
* sh_ctrlsub - function to do the ^D thingy
* @argu: arguments
* Return: 0, on success
*/
int sh_ctrlsub(char **argu)
{
	(void)argu;
	free(argu);
	return (200);
}

/**
*_forkset - make a fork
*@arg: path argument
*@a: well you’ll see
*@env: the env
*@pointer: users line of thought
*@o: identify process
*@s: tester variable
*Return: 0 success
*/

int _forkset(char **arg, char **a, char **env, char *pointer, int o, int s)
{

	pid_t c;
	int state, k = 0;
	char *f = "%s: %d: %s: not found\n";

	if (arg[0] == NULL)
		return (1);
	for (k = 0; k < sh_numprefab(); k++)
	{
		if (_strcmp(arg[0], prefabs[k]) == 0)
			return (prefab_sub[k](arg));
	}
	c = fork();
	if (c == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, f, a[0], o, arg[0]);
			if (!s)
				free(arg[0]);
			free(arg);
			free(pointer);
			exit(errno);
		}
	}
	else
	{
		wait(&state);
		return (state);
	}
	return (0);
}
