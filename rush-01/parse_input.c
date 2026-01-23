int	parse_input(char *str, int *views, int size)
{
	int	i;
	int	j;
	int	views_len;

	i = 0;
	j = 0;
	views_len = size * 4;
	if (size < 1 || size > 9)
		return (0);
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '0' + size)
		{
			if (j >= views_len)
				return (0);
			views[j++] = str[i] - '0';
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (j == views_len);
}
