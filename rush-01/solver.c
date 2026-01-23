#define SIZE 4

int	check_views(int grid[SIZE][SIZE], int *views);
int	is_valid(int grid[SIZE][SIZE], int row, int col, int num);

int	solve(int grid[SIZE][SIZE], int *views, int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == (SIZE * SIZE))
		return (check_views(grid, views));
	row = pos / SIZE;
	col = pos % SIZE;
	num = 1;
	while (num <= SIZE)
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
