#include "shell.h"

/**
 * _myhistory - displ
 * @info: Structure
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets string
 * @info: parameter struct
 * @str: the alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *h;
	char x;
	int ret;

	h = _strchr(str, '=');
	if (!p)
		return (1);
	x = *h;
	*h = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*h = x;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0
 */
int set_alias(info_t *info, char *str)
{
	char *h;

	h = _strchr(str, '=');
	if (!h)
    {
        return (1);
    }
	if (!*++h){
		return (unset_alias(info, str));
}
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias
 * @node: alias node
 *
 * Return: 0 or 1
 */
int print_alias(list_t *node)
{
	char *r = NULL;
	 char *f = NULL;

	if (node)
	{
		r = _strchr(node->str, '=');
		for (f = node->str; f <= r; f++)
			_putchar(*f);
		_putchar('\'');
		_puts(r + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin man alias
 * @info: Structure
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int w = 0;
	char *l = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (w = 1; info->argv[w]; w++)
	{
		l = _strchr(info->argv[w], '=');
		if (l) {
			set_alias(info, info->argv[i]);
		}
		else{
			print_alias(node_starts_with(info->alias, info->argv[w], '='));
		}
	}

	return (0);
}
