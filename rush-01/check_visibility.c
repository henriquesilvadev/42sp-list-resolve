int	check_line(int *line, int expected)
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

int	check_views(int grid[4][4], int views[16])
{
	int	i;
	int	line[4];

	i = 0;
	while (i < 4)
	{
		line[0] = grid[0][i];
		line[1] = grid[1][i];
		line[2] = grid[2][i];
		line[3] = grid[3][i];
		if (!check_line(line, views[i]))
			return (0);

		line[0] = grid[3][i];
		line[1] = grid[2][i];
		line[2] = grid[1][i];
		line[3] = grid[0][i];
		if (!check_line(line, views[i + 4]))
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (!check_line(grid[i], views[i + 8]))
			return (0);
		line[0] = grid[i][3];
		line[1] = grid[i][2];
		line[2] = grid[i][1];
		line[3] = grid[i][0];
		if (!check_line(line, views[i + 12]))
			return (0);
		i++;
	}
	return (1);
}
