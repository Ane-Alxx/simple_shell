#include "shell.h"

/**
* active - function for the active
* @i: struct
* Return: 1 or 0, success or fail
*/
int active(info_t *i)
{
	return (isatty(STDIN_FILENO) && i->rfd <= 2);
}

/**
* delimeter_on - function for delimeter on
* @e: char
* @d: tstring
* Return: 1 or 0 success or fail
*/
int delimeter_on(char e, char *d)
{
	while (*d)
		if (*d++ == e)
			return (1);
	return (0);
}

/**
* _isalpha - function for is alpha
* @o: character
* Return: 1 if c is alphabetic, 0 otherwise
*/

int _isalpha(int o)
{
	if ((o >= 'a' && o <= 'z') || (o >= 'A' && o <= 'Z'))
		return (1);
	else
		return (0);
}

/**
* _atoi - function for attoi
* @t: tstring
* Return: 0 success
*/

int _atoi(char *t)
{
	int m, s = 1, g = 0, p;
	unsigned int l = 0;

	for (m = 0; t[m] != '\0' && g != 2; m++)
	{
		if (t[m] == '-')
			s *= -1;

		if (t[m] >= '0' && t[m] <= '9')
		{
			g = 1;
			l *= 10;
			l += (t[m] - '0');
		}
		else if (g == 1)
			g = 2;
	}

	if (s == -1)
		p = -l;
	else
		p = l;

	return (p);
}
