#define SIZE 4

static int	check_line(int *line, int expected)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	while (i < SIZE)
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

int	check_views(int grid[SIZE][SIZE], int *views)
{
	int	i;
	int	k;
	int	line[SIZE];

	i = 0;
	while (i < SIZE)
	{
		k = 0;
		while (k < SIZE)
		{
			line[k] = grid[k][i];
			k++;
		}
		if (!check_line(line, views[i]))
			return (0);

		k = 0;
		while (k < SIZE)
		{
			line[k] = grid[SIZE - 1 - k][i];
			k++;
		}
		if (!check_line(line, views[i + SIZE]))
			return (0);
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (!check_line(grid[i], views[i + (SIZE * 2)]))
			return (0);
		k = 0;
		while (k < SIZE)
		{
			line[k] = grid[i][SIZE - 1 - k];
			k++;
		}
		if (!check_line(line, views[i + (SIZE * 3)]))
			return (0);
		i++;
	}
	return (1);
}
