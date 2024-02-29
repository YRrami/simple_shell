#include "shell.h"

/**
 * interactive - bring back true if shell is in interactive mode
 * @info: structer address
 * Return: 1 if interactive mode and 0 if otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @c: char
 * @delim: its a delimeter string
 * Return: back 1 if true and 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
        {
            return (1);
        }
	return (0);
}

/**
 *_isalpha - detect alphabetic characters
 *@c: chart to input
 *Return: back 1 if c is alphabetic and 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return (1);
    }
	else{
		return (0);
	}
}

/**
 *_atoi - converts str to int
 *@s: str to be converted
 *Return: back 0 if no nums in str and converted num otherwise
 */

int _atoi(char *s)
{
	int x;
	int mark = 1;
	int red = 0;
	int out;
	unsigned int result = 0;

	for (x = 0;  s[i] != '\0' && red != 2; x++)
	{
		if (s[x] == '-'){
			mark *= -1;
		}
		if (s[x] >= '0' && s[x] <= '9')
		{
			red = 1;
			result *= 10;
			result += (s[x] - '0');
		}
		else if (red == 1)
			red = 2;
	}

	if (mark == -1){
		out = -result;
	}
	else {
		out = result;
	}
	return (out);
}
