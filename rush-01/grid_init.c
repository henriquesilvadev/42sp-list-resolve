#define SIZE 4

void	init_grid(int grid[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			grid[i][j++] = 0;
		i++;
	}
}
