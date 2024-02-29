#include "shell.h"

/**
 *_eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	long int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_eputchar(str[x]);
		x++;
	}
}

/**
 * _eputchar - writes the character c
 * @c: character to print
 * Return: 1
 */
int _eputchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
    {
        buf[x++] = c;
    }
	return (1);
}

/**
 * _putfd - writes the character
 * @c: The character print
 * @fd: The filedescriptor
 * Return: 1
 */
int _putfd(char c, int fd)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(fd, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
	return (1);
}

/**
 *_putsfd - prints an input
 * @str: the string to be printed
 * @fd: the filedescriptor
 * Return: the number of chars
 */
int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
    {
        return (0);
    }
	while (*str)
	{
		x = x + _putfd(*str++, fd);
	}
	return (x);
}
