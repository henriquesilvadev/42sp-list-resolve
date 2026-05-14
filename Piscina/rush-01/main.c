int	parse_input(char *str, int *views);
void	init_grid(int grid[4][4]);
int	solve(int grid[4][4], int *views, int pos);
void	print_grid(int grid[4][4]);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	views[16];

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
