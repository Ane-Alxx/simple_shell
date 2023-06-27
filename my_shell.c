#include "shell.h"
/**
* main - entry point
* @c: number of arguments
* @v: the actual arguments
* @env: the evironment
* Return: 0 to exit
*/
int main(int c, char **v, char **env)
{
	int p_val = 0, state = 0, path = 0;
	char *ln = NULL, **coms = NULL;
	(void)c;
	while (1)
	{
		errno = 0;
		ln = _getlinesub();
		if (ln == NULL && errno == 0)
			return (0);
		if (ln)
		{
			p_val++;
			coms = tokenize(ln);
			if (!coms)
				free(ln);
			if (!_strcmp(coms[0], "env"))
				_getenv(env);
			else
			{
				path = _val_pathsub(&coms[0], env);
				state = _forkset(coms, v, env, ln, p_val, path);
					if (state == 200)
					{
						free(ln);
						return (0);
					}
				if (path == 0)
					free(coms[0]);
			}
			free(coms);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(state);
		}
		free(ln);
	}
	return (state);
}
