#define SIZE 4
#define VIEWS 16

int	parse_input(char *str, int *views)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '0' + SIZE)
		{
			if (j >= VIEWS)
				return (0);
			views[j++] = str[i] - '0';
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	return (j == VIEWS);
}
