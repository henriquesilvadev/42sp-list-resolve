#include <unistd.h>

int		parse_input(char *str, int *views, int size);
void	init_grid(int size, int grid[size][size]);
int		solve(int size, int grid[size][size], int *views, int pos,
			int cells_count);
void	print_grid(int size, int grid[size][size]);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	static int	grid_size = 4;
	static int	views_count = 0;
	int			grid[grid_size][grid_size];
	int			views[grid_size * 4];

	views_count = grid_size * grid_size;
	if (argc != 2 || !parse_input(argv[1], views, grid_size))
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_grid(grid_size, grid);
	if (!solve(grid_size, grid, views, 0, views_count))
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_grid(grid_size, grid);
	return (0);
}
