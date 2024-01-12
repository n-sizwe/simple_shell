#include "shell.h"

/**
 * set_alias - Adds or updates an alias in the shell
 * @info: Structure containing relevant arguments. Used to maintain
 *          constant function prototype.
 * @str: The alias string to set
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *equal_sign;

	equal_sign = _strchr(str, '=');
	if (!equal_sign)
		return 1;
	if (!*++equal_sign)
		return unset_alias(info, str);

	unset_alias(info, str);
	return add_node_end(&(info->alias), str, 0) == NULL;
}

/**
 * print_alias - Prints an alias string
 * @node: The alias node to print
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *equal_sign = NULL, *alias_value = NULL;

	if (node)
	{
		equal_sign = _strchr(node->str, '=');
		for (alias_value = node->str; alias_value <= equal_sign; alias_value++)
			_putchar(*alias_value);
		_putchar('\'');
		_puts(equal_sign + 1);
		_puts("'\n");
		return 0;
	}
	return 1;
}

/**
 * _myalias - Mimics the alias builtin command (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *equal_sign = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return 0;
	}
	for (i = 1; info->argv[i]; i++)
	{
		equal_sign = _strchr(info->argv[i], '=');
		if (equal_sign)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return 0;
}
