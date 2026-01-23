#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
int	ft_strlen(char *str)
{
    int	len = 0;

    while (str[len])
        len++;
    return (len);
}