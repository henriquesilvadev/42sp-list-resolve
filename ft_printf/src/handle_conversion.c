/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:29:10 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/04 12:35:46 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_putchar_count(int c);
static int	ft_print_ptr(unsigned long long addr);
static int	ft_print_str(char *str);
static int	ft_print_nbr(unsigned int nbr, int uppercase, int base);

int	handle_conversion(char specifier, va_list *args)
{
	if (specifier == 's')
		return (ft_print_str(va_arg(*args, char *)));
	if (specifier == 'c')
		return (ft_putchar_count(va_arg(*args, int)));
	if (specifier == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(*args, void *)));
	if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	if (specifier == 'u')
		return (ft_print_nbr(va_arg(*args, unsigned int), 0, 10));
	if (specifier == 'X')
		return (ft_print_nbr(va_arg(*args, unsigned int), 1, 16));
	if (specifier == 'x')
		return (ft_print_nbr(va_arg(*args, unsigned int), 0, 16));
	if (specifier == '%')
		return (ft_putchar_count('%'));
	return (0);
}

static int	ft_print_ptr(unsigned long long addr)
{
	int	len;

	if (addr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	len = write(1, "0x", 2);
	len += ft_putnbr_base_fd(addr, "0123456789abcdef", 1);
	return (len);
}

static int	ft_putchar_count(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

static int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	ft_print_nbr(unsigned int nbr, int uppercase, int base)
{
	char	*digits;

	digits = NULL;
	if (base == 16)
	{
		if (uppercase)
			digits = "0123456789ABCDEF";
		else
			digits = "0123456789abcdef";
	}
	if (base == 10)
		digits = "0123456789";
	return (ft_putnbr_base_fd(nbr, digits, 1));
}
