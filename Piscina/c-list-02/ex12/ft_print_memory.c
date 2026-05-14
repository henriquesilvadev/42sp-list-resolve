/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 17:05:15 by hhonorio          #+#    #+#             */
/*   Updated: 2026/01/20 09:06:39 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_puthexbyte(unsigned char b)
{
	char	*hex;

	hex = "0123456789abcdef";
	ft_putchar(hex[b / 16]);
	ft_putchar(hex[b % 16]);
}

void	ft_puthexaddr(unsigned long n)
{
	char	*hex;
	char	buf[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buf[i] = hex[n % 16];
		n /= 16;
		i--;
	}
	write(1, buf, 16);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned int		j;
	unsigned char		*p;

	if (size == 0)
		return (addr);
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_puthexaddr((unsigned long)(p + i));
		ft_putstr(": ");
		j = 0;
		while (j < 16)
		{
			if (i + j < size)
				ft_puthexbyte(p[i + j]);
			else
				ft_putstr("  ");
			if (j % 2 == 1)
				ft_putchar(' ');
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (p[i + j] >= 32 && p[i + j] <= 126)
				ft_putchar(p[i + j]);
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
	