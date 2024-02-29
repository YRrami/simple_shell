#include "shell.h"

/**
 * _myenv - prints environment
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);

	return (0);
}

/**
 * _getenv - gets the valuee
 * @info: Structure containing potential argument
 * @name: var name
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *x;

	while (node)
	{
		x = starts_with(node->str, name);
		if (p && *x){
			return (x);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
    {
        return (0);
    }
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	long int p;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (p = 1; p <= info->argc; p++)
		_unsetenv(info, info->argv[p]);

	return (0);
}

/**
 * populate_env_list - populates anv linked list
 * @info: Structure containing potential
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}
