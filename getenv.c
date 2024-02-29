#include "shell.h"

/**
 * get_environ - returns the string
 * @info: Structure
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
 * _unsetenv - Remove an environment v
 * @info: Structure
 * @var: the string var
 *  Return: 1 or 0
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t x = 0;
	char *h;

	if (!node || !var)
    {
        return (0);
    }

	while (node)
	{
		h = starts_with(node->str, var);
		if (h && *h == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		x++;
	}
	return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment
 * @info: Structure containing potential arguments
 * @var: the string
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *b = NULL;
	list_t *node;
	char *s;

	if (!var || !value){
		return (0);
	}
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!b) {
		return (1);
	}
	_strcpy(b, var);
	_strcat(b, "=");
	_strcat(b, value);
	node = info->env;
	while (node)
	{
		s = starts_with(node->str, var);
		if (s && *s == '=')
		{
			free(node->str);


			node->str = b;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), b, 0);
	free(b);
	info->env_changed = 1;
	return (0);
}
