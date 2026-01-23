int	is_valid(int size, int grid[size][size], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
