int	is_valid(int grid[4][4], int row, int col, int num);
int	check_views(int grid[4][4], int views[16]);

int	solve(int grid[4][4], int views[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_views(grid, views));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, views, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
