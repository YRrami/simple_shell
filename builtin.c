#include "shell.h"

/**
 * _myexit - exits
 * @info: Structure constant function prototype.
 *  Return: exits
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exitck;

	if (info->argv[1])
	{
		exitck = _erratoi(info->argv[1]);
		if (exitck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current dir
 * @info: Structure
 *  Return: Always 0
 */
int _mycd(info_t *info)
{
	char *x;
	char *rd;
	char buff[1024];
	int chdir_ret;

	x = getcwd(buff, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!rd){
			chdir_ret = /* TODO: what should this be? */
		}
				chdir((rd = _getenv(info, "PWD=")) ? rd : "/");
		else {
			chdir_ret = chdir(dir);
		}
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((rd = _getenv(info, "OLDPWD=")) ? rd : "/");
	}
	else {
		chdir_ret = chdir(info->argv[1]);

if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_ar;

	arg_ar = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_ar); /* temp att_unused workaround */
	return (0);
}
