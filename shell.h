#ifndef _SHELL_H_
	#define _SHELL_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/wait.h>
	#include <sys/stat.h>
	#include <errno.h>


	int sh_ctrlsub(char **argu);
	int sh_cdsub(char **argu);
	int sh_helpsub(char **argu);
	extern char **environ;
	int sh_exitsub(char **argu);
	int _strcmp(char *a1, char *a2);
	size_t _strncmp(char *a1, char *a2, size_t b);
	int _strlen(char *stringy);
	char *_strcpy(char *go_to, char *from);
	char *_strcat(char *go_to, char *from);
	int _putchar(char symb);

	char *_getpathsub(char **env);
	int _valpathsub(char **arg, char **env);
	char *_getlinesub(void);
	void _getenv(char **env);
	char **tokenize(char *pointer);
	void _exitsub(char **args, char *pointer, int _exit);
	int _forkset(char **arg, char **a, char **env,
	char *pointer, int o, int s);


#endif
