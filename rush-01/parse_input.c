int	parse_input(char *str, int views[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			if (j >= 16)
				return (0);
			views[j++] = str[i] - '0';
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (j == 16);
}
