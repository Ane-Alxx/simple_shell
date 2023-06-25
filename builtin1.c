#include "shell.h"

/**
* _unikhistory - function for unikhistory.
* @i: struct
* Return: Always 0
*/
int _unikhistory(info_t *i)
{
	p_list(i->history);
	return (0);
}

/**
* unset_alias - function for
* @i: you know this to create struct
* @s: stringy thingy
* Return: Always 0 on success, 1 on error
*/
int unset_alias(info_t *i, char *s)
{
	char *o, v;
	int t;

	o = _strchr(s, '=');
	if (!o)
		return (1);
	v = *o;
	*o = 0;
	t = del_node(&(i->alias),
		get_nodeindex(i->alias, node_s(info->alias, s, -1)));
	*o = v;
	return (t);
}

/**
* set_alias - functionalists t
* @i: structure
* @s: string
*
* Return: 0 or 1, success or fail
*/
int set_alias(info_t *i, char *s)
{
	char *o;

	o = _strchr(s, '=');
	if (!o)
		return (1);
	if (!*++o)
		return (unset_alias(i, s));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - display function
* @n: node
* Return: 1 or 0, success or fail
*/
int print_alias(list_t *n)
{
	char *o = NULL, *s = NULL;

	if (node)
	{
		o = _strchr(n->str, '=');
		for (s = node->str; s <= o; s++)
		_putchar(*s);
		_putchar('\'');
		_puts(o + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
* _unikalias - function to copy builtin alias
* @o: information
* Return: Always 0
*/
int _unikalias(info_t *o)
{
	int k = 0;
	char *ptr = NULL;
	list_t *n = NULL;

	if (o->argc == 1)
	{
		n = o->alias;
		while (n)
		{
			print_alias(n);
			n = n->next;
		}
		return (0);
	}
	for (k = 1; o->argv[k]; k++)
	{
		ptr = _strchr(o->argv[k], '=');
		if (ptr)
			set_alias(o, o->argv[k]);
		else
			print_alias(node_s(o->alias, o->argv[k], '='));
	}

	return (0);
}
