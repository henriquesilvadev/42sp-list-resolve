/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:29:10 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/31 12:09:12 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_putchar_count(int c);
static int	ft_print_ptr(unsigned long long addr);
static int	ft_print_hex(unsigned int nbr, int upper);

int	handle_conversion(char c, va_list *args)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(*args, char *);
		if (!str)
			str = "(null)";
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	if (c == 'c')
		return (ft_putchar_count(va_arg(*args, int)));
	if (c == 'p')
		return (ft_print_ptr((unsigned long long)va_arg(*args, void *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_count(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*args, unsigned int)));
	if (c == 'X')
		return (ft_print_hex((unsigned int)va_arg(*args, unsigned int), 1));
	if (c == 'x')
		return (ft_print_hex((unsigned int)va_arg(*args, unsigned int), 0));
	if (c == '%')
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
