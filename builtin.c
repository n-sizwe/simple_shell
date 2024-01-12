#include "shell.h"

/**
 * exit_shell - Exits the shell
 * @info: Structure containing relevant arguments. Used to maintain
 *          constant function prototype.
 * Return: Exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int exit_shell(info_t *info)
{
	int exit_status;

	if (info->argv[1])  /* If there is an exit argument */
	{
		exit_status = _convert_to_int(info->argv[1]);
		if (exit_status == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_print_string(info->argv[1]);
			_putchar('\n');
			return 1;
		}
		info->err_num = _convert_to_int(info->argv[1]);
		return -2;
	}
	info->err_num = -1;
	return -2;
}

/**
 * change_directory - Changes the current directory of the process
 * @info: Structure containing relevant arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int change_directory(info_t *info)
{
	char *current_dir, *target_dir, buffer[1024];
	int chdir_ret;

	current_dir = get_current_directory(buffer, 1024);
	if (!current_dir)
		_print_string("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		target_dir = _get_environment_variable(info, "HOME=");
		if (!target_dir)
			chdir_ret = /* TODO: Set default directory here */
				change_directory((target_dir = _get_environment_variable(info, "PWD=")) ? target_dir : "/");
		else
			chdir_ret = change_directory(target_dir);
	}
	else if (_compare_strings(info->argv[1], "-") == 0)
	{
		if (!_get_environment_variable(info, "OLDPWD="))
		{
			_print_string(current_dir);
			_putchar('\n');
			return 1;
		}
		_print_string(_get_environment_variable(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: Set default directory here */
			change_directory((target_dir = _get_environment_variable(info, "OLDPWD=")) ? target_dir : "/");
	}
	else
		chdir_ret = change_directory(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_print_string(info->argv[1]), _putchar('\n');
	}
	else
	{
		_set_environment_variable(info, "OLDPWD", _get_environment_variable(info, "PWD="));
		_set_environment_variable(info, "PWD", get_current_directory(buffer, 1024));
	}
	return 0;
}

/**
 * show_help - Displays help information
 * @info: Structure containing relevant arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int show_help(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_print_string("help call works. Function not yet implemented \n");
	if (0)
		_print_string(*arg_array); /* Temporary unused variable workaround */
	return 0;
}
