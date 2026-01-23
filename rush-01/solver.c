int	is_valid(int size, int grid[size][size], int row, int col, int num);
int	check_views(int size, int grid[size][size], int *views);

int	solve(int size, int grid[size][size], int *views, int pos,
		int cells_count)
{
	int	row;
	int	col;
	int	num;

	if (pos == cells_count)
		return (check_views(size, grid, views));
	row = pos / size;
	col = pos % size;
	num = 1;
	while (num <= size)
	{
		if (is_valid(size, grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(size, grid, views, pos + 1, cells_count))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
