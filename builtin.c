#include "shell.h"

/**
* _unikexit - function for unikexit
* @f: defined struct fo this program
* Return: value on success
*/
int _unikexit(info_t *f)
{
	int ek;

	if (f->argv[1])
	{
		ek = _erroratoi(f->argv[1]);
		if (ek == -1)
		{
			f->status = 2;
			p_error(f, "Illegal number: ");
			_envputs(f->argv[1]);
			_envputchar('\n');
			return (1);
		}
		f->err_num = _erroratoi(info->argv[1]);
		return (-2);
	}
	f->err_num = -1;
	return (-2);
}

/**
* _unikcd - function for uni cd
* @o: maintainer guy
* Return: Always 0
*/
int _unikcd(info_t *o)
{
	char *z, *fo, buff[1024];
	int ch;

	z = getcwd(buff, 1024);
	if (!z)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!o->argv[1])
	{
		fo = _getenv(o, "HOME=");
		if (!fo)
			ch = /* TODO: what should this be? */
				ch((fo = _getenv(o, "PWD=")) ? fo : "/");
		else
			ch = ch(fo);
	}
	else if (_strcmp(o->argv[1], "-") == 0)
	{
		if (!_envgt(o, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(o, "OLDPWD=")), _putchar('\n');
		ch = /* TODO: what should this be? */
			ch((fo = _getenv(o, "OLDPWD=")) ? fo : "/");
	}
	else
		ch = chdir(o->argv[1]);
	if (ch == -1)
	{
		p_error(o, "can't cd to ");
		_envputs(o->argv[1]), _envputchar('\n');
	}
	else
	{
		_setenv(o, "OLDPWD", _getenv(o, "PWD="));
		_setenv(o, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

/**
* _unikhelp - function for unikhrlp
* @o: information
* Return: Always 0
*/
int _unikhelp(info_t *o)
{
	char **arg_a;

	arg_a = o->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_a);
	return (0);
}
