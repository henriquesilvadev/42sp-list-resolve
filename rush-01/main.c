#define SIZE 4
#define VIEWS 16

int	parse_input(char *str, int *views);
void	init_grid(int grid[SIZE][SIZE]);
int	solve(int grid[SIZE][SIZE], int *views, int pos);
void	print_grid(int grid[SIZE][SIZE]);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	grid[SIZE][SIZE];
	int	views[VIEWS];

	if (argc != 2 || !parse_input(argv[1], views))
	{
		ft_putstr("Error\n");
		return (1);
	}
	init_grid(grid);
	if (!solve(grid, views, 0))
	{
		ft_putstr("Error\n");
		return (1);
	}
	print_grid(grid);
	return (0);
}
