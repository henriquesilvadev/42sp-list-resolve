static int	check_line(int *line, int expected)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			seen++;
		}
		i++;
	}
	return (seen == expected);
}

int	check_views(int grid[4][4], int *views)
{
	int	i;
	int	k;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		k = 0;
		while (k < 4)
		{
			line[k] = grid[k][i];
			k++;
		}
		if (!check_line(line, views[i]))
			return (0);

		k = 0;
		while (k < 4)
		{
			line[k] = grid[4 - 1 - k][i];
			k++;
		}
		if (!check_line(line, views[i + 4]))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (!check_line(grid[i], views[i + (4 * 2)]))
			return (0);
		k = 0;
		while (k < 4)
		{
			line[k] = grid[i][4 - 1 - k];
			k++;
		}
		if (!check_line(line, views[i + (4 * 3)]))
			return (0);
		i++;
	}
	return (1);
}
