#include "shell.h"

/**
 * _erratoi - converts a string to int
 * @s: the string
 * Return: 0
 */
int _erratoi(char *s)
{
	long int x = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */
	for (x = 0;  s[x] != '\0'; x++)
	{
		if (s[x] >= '0' && s[x] <= '9')
		{
			result *= 10;
			result += (s[x] - '0');
			if (result > INT_MAX){
				return (-1);
			}
		}
		else{
			return (-1);
		}
	}
	return (result);
}

/**
 * print_error - prints error message
 * @info: the parameter
 * @estr: string
 * Return: 0
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - function
 * @input: the input
 * @fd: the filed
 * Return: number of characters
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int e, c = 0;
	unsigned int _aboss_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_aboss_ = -input;
		__putchar('-');
		c++;
	}
	else {
		_aboss_ = input;
	}
	current = _aboss_;
	for (e = 1000000000; e > 1; e /= 10)
	{
		if (_aboss_ / e)
		{
			__putchar('0' + current / e);
			c++;
		}
		current %= e;
	}
	__putchar('0' + current);
	c++;

	return (c);
}

/**
 * convert_number - converter F
 * @num: num
 * @base: B
 * @flags: arg f
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *arr;
	static char buff[50];
	char s = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		s = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];


	*ptr = '\0';


	do	{
		*--ptr = arr[n % base];
		n /= base;
	} while (n != 0);

	if (sign) {
		*--ptr = s;
	}
	return (ptr);
}

/**
 * remove_comments - function replacor
 * @buf: address of sss
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int x;

	for (x = 0; buf[x] != '\0'; x++)
		if (buf[x] == '#' && (!i || buf[x - 1] == ' '))
		{
			buf[x] = '\0';
			break;

		}
}
