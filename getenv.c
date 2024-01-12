/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
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
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * Return: 1 on delete, 0 otherwise
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node;
	char *p;

	if (!info->env || !var)
		return (0);

	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), node->index);
			return (info->env_changed);
		}
		node = node->next;
	}

	return (0);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 * Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *env_var;

	if (!var || !value)
		return (0);

	env_var = _strjoin(var, "=", value);
	if (!env_var)
		return (1);

	if (update_env_var(info, var, env_var) == 0)
	{
		free(env_var);
		return (0);
	}

	add_node_end(&(info->env), env_var, 0);
	info->env_changed = 1;
	free(env_var);
	return (0);
}

/**
 * update_env_var - Updates an existing environment variable.
 * @info: Structure containing potential arguments.
 * @var: the string env var property
 * @env_var: the new environment variable string
 * Return: 0 on success, 1 on failure
 */
int update_env_var(info_t *info, char *var, char *env_var)
{
	list_t *node;
	char *p;

	if (!info->env || !var || !env_var)
		return (1);

	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = env_var;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}

	return (1);
}
