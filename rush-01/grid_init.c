void	init_grid(int size, int grid[size][size])
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			grid[i][j++] = 0;
		i++;
	}
}
