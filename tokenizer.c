#include "shell.h"

/**
 * **strtow - splits a str
 * @str: string
 * @d: string
 * Return: 1
 */

char **strtow(char *str, char *d)
{
	int x;
	int s;
	int w;
	int m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
    {
        return (NULL);
    }
	if (!d){
		d = " ";
	}
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			numwords++;

	if (numwords == 0)
    {
        return (NULL);
    }
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s) {
		return (NULL);
	}
	for (x = 0, s = 0; s < numwords; s++)
	{
		while (is_delim(str[x], d)) {
			x++;
		}
		w = 0;
		while (!is_delim(str[x + w], d) && str[x + w]){
			w++;
		}
		s[j] = malloc((w + 1) * sizeof(char));
		if (!s[j])
		{
			for (w = 0; w < s; w++)
            {
                free(s[w]);
            }
			free(s);
			return (NULL);
		}
		for (m = 0; m < w; m++)
        {
            s[j][m] = str[x++];
        }
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - cut string to words
 * @str:  input str
 * @d: del
 * Return: a pointer
 */
char **strtow2(char *str, char d)
{
	int x ; int w; int k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
    {
        return (NULL);
    }
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d) {
			numwords++;
		    }
	if (numwords == 0){
		return (NULL);
	}
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s){
		return (NULL);
	}
	for (x = 0, w = 0; w < numwords; w++)
	{
		while (str[x] == d && str[x] != d){
			x++;
		}
		k = 0;
		while (str[x + k] != d && str[x + k] && str[x + k] != d){
			k++;
		}
		s[w] = malloc((k + 1) * sizeof(char));
		if (!s[w])
		{
			for (k = 0; k < w; k++) {
				free(s[k]);
			}
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++) {
			s[w][m] = str[x++];
		}
		s[w][m] = 0;
	}
	s[w] = NULL;
	return (s);
}
