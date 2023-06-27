#include "shell.h"
/**
* tokenize - tfunction for tokinzing
* @pointer: mean input
* Return: a ptr to arr of ptrs
*/

char **tokenize(char *pointer)
{
	char **u_com = NULL;
	char *toke = NULL;
	size_t k = 0;
	int s = 0;

	if (pointer == NULL)
		return (NULL);

	for (k = 0; pointer[k]; k++)
	{
		if (pointer[k] == ' ')
			s++;
	}
	if ((s + 1) == _strlen(pointer))
		return (NULL);
	u_com = malloc(sizeof(char *) * (s + 2));
	if (u_com == NULL)
		return (NULL);

	toke = strtok(pointer, " \n\t\r");

	for (k = 0; toke != NULL; k++)
	{
		u_com[k] = toke;
		toke = strtok(NULL, " \n\t\r");
	}
	u_com[k] = NULL;
	return (u_com);
}
