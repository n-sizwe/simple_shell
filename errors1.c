/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted
 * Return: Converted integer on success, -1 on error (overflow or non-digit characters)
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	// Skip leading '+' if present
	if (*s == '+')
		s++;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);  // Return -1 on overflow
		}
		else
			return (-1);  // Return -1 on encountering non-digit characters
	}
	return (result);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: void
 */
void print_error(info_t *info, char *estr)
{
	if (info->fname)
		_eputs(info->fname);

	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * remove_comments - replaces the first instance of '#' with '\0'
 * @buf: address of the string to modify
 * Return: void
 */
void remove_comments(char *buf)
{
	int i = 0;

	while (buf[i] && (buf[i] != '#' || (i > 0 && buf[i - 1] == ' ')))
		i++;

	if (buf[i] == '#')
		buf[i] = '\0';
}
