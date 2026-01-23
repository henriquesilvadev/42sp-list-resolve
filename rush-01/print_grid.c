#include <unistd.h>

void	ft_putchar(char c);

void	print_grid(int size, int grid[size][size])
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
