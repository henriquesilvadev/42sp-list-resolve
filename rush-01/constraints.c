#define SIZE 4

int	is_valid(int grid[SIZE][SIZE], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}
