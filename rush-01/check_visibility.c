int	check_line(int size, int *line, int expected)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	while (i < size)
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

int	check_views(int size, int grid[size][size], int *views)
{
	int	i;
	int	k;
	int	line[size];

	i = 0;
	while (i < size)
	{
		k = 0;
		while (k < size)
		{
			line[k] = grid[k][i];
			k++;
		}
		if (!check_line(size, line, views[i]))
			return (0);

		k = 0;
		while (k < size)
		{
			line[k] = grid[size - 1 - k][i];
			k++;
		}
		if (!check_line(size, line, views[i + size]))
			return (0);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (!check_line(size, grid[i], views[i + (size * 2)]))
			return (0);
		k = 0;
		while (k < size)
		{
			line[k] = grid[i][size - 1 - k];
			k++;
		}
		if (!check_line(size, line, views[i + (size * 3)]))
			return (0);
		i++;
	}
	return (1);
}
