#include "shell.h"

/**
* _strcat - join two strings
* @go_to: go here
*
* @from: from here
* Return: 0, on success
*/



char *_strcat(char *go_to, char *from)
{
	int k, m = 0;

	for (k = 0; go_to[k] != '\0'; k++)
	{
	}
	for (m = 0; from[m] != '\0'; m++)
	{
		go_to[k] = from[m];
		k++;

	}
	go_to[k] = '\0';
return (go_to);
}



/**
* _strcmp - check similarities
* @a1: first string
* @a2: second string
* Return: strings
*
*/

int _strcmp(char *a1, char *a2)
{
	int k = 0;
	int l;

	while (a1[k] != 0 && a2[k] != 0 && a1[k] == a2[k])
		k++;
	l = a1[k] - a2[k];
	return (l);

}

/**
* _strlen - length of string
* @stringy: the string na
* Return: length
*/

int _strlen(char *stringy)
{
	int k;

	for (k = 0; stringy[k] != 0; k++)
		;

	return (k);
}

/**
*_strncmp -  function for strcopm.
*@a1: string one
*@a2: string two
*@b: length
* Return: dif
*/

size_t _strncmp(char *a1, char *a2, size_t b)
{
	size_t k, m;

	for (m = 0; a1[m] != '\0' && m < b; m++)
	{
		k = a1[m] - a2[m];

		if (k != 0)
		{
			return (k);
		}
	}
	return (0);
}

/**
* _strcpy - function for string cop
* @go_to: location
* @from: location
*
* Return: point
*/

char *_strcpy(char *go_to, char *from)
{
	int k = 0;

	for (k = 0; from[k] != '\0'; k++)
	{
		go_to[k] = from[k];
	}
	go_to[k + 1] = 0;
	return (go_to);
}

















