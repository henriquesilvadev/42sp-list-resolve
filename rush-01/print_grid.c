#define SIZE 4

void	ft_putchar(char c);

void	print_grid(int grid[SIZE][SIZE])
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < SIZE - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
