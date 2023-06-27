#include "shell.h"

/**
* _getlinesub-  function for get line
* Return: pointer
*/

char *_getlinesub(void)
{
	char *pointer = NULL;
	size_t c = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&pointer, &c, stdin) == -1)
	{
		free(pointer);
		return (NULL);
	}

	return (pointer);
}
