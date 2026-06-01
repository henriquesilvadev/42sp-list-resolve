/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:29:10 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/01 12:20:28 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <complex.h>
#include <stdarg.h>

static int	ft_putchar_count(int c);
static int	ft_print_ptr(unsigned long long addr);
static int	ft_print_hex(unsigned int nbr, int upper);
static int	digit_len(unsigned int nbr);

int	handle_conversion(t_conversion conv, va_list *args)
{
	char			*str;
	unsigned int	nbr;
	size_t			content_len;
	size_t			padding;

	if (conv.specifier == 's')
	{
		str = va_arg(*args, char *);
		if (!str)
			str = "(null)";
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	if (conv.specifier == 'c')
		return (ft_putchar_count(va_arg(*args, int)));
	if (conv.specifier == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(*args, void *)));
	if (conv.specifier == 'd' || conv.specifier == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	if (conv.specifier == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	if (conv.specifier == 'X')
	{
		nbr = (unsigned int) va_arg(*args, unsigned int);
		content_len = digit_len(nbr);
		padding = conv.width - content_len;
		return (ft_print_hex((unsigned int)va_arg(*args, unsigned int), 1));
	}
	if (conv.specifier == 'x')
		return (ft_print_hex((unsigned int)va_arg(*args, unsigned int), 0));
	if (conv.specifier == '%')
		return (ft_putchar_count('%'));
	return (0);
}

static int	ft_print_ptr(unsigned long long addr)
{
	int	len;

	len = write(1, "0x", 2);
	len += ft_putnbr_base_fd(addr, "0123456789abcdef", 1);
	return (len);
}

static int	ft_print_hex(unsigned int nbr, int upper)
{
	int	len;

	len = 0;
	if (upper == 1)
		len += ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1);
	else
		len += ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
	return (len);
}

static int	ft_putchar_count(int c)
{
	if (!c)
		return (ft_strlen("(null)"));
	ft_putchar_fd(c, 1);
	return (1);
}

static int	digit_len(unsigned int nbr)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		count += 1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
