#include <unistd.h>

void	ft_putchar(char c);

void	print_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putchar(grid[i][j] + '0');
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
