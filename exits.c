#include "shell.h"

/**
 **_strncpy - string copying
 *@dest: the destination string
 *@src: src str
 *@n: the amount of chars to c
 *Return: string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x;
	int q;
	char *w = dest;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		q = x;
		while (q < n)
		{
			dest[q] = '\0';
			q++;
		}
	}
	return (w);
}

/**
 **_strncat - concatenatic
 *@dest: the first var
 *@src: the second var
 *@n: var
 *Return: string
 */
char *_strncat(char *dest, char *src, int n)
{
	int x;
	int l;
	char *s = dest;

	x = 0;
	l = 0;
	while (dest[x] != '\0')
    {
        x++;
    }
	while (src[l] != '\0' && l < n)
	{
		dest[x] = src[l];
		x++;
		l++;
	}
	if (l < n) {
		dest[x] = '\0';
	}
	return (s);
}

/**
 **_strchr - locates a character
 *@s: the string
 *@c: the character
 *Return: (s)
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c){
			return (s);
		}
	} while (*s++ != '\0');

	return (NULL);
}
