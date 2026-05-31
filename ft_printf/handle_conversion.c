/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 13:29:10 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/31 08:30:27 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_ptr(unsigned long long addr);

int	handle_conversion(char c, va_list *args)
{
	char	*str;
	int		chr;
	void	*ptr;

	if (c == 's')
	{
		str = va_arg(*args, char *);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	if (c == 'c')
	{
		chr = va_arg(*args, int);
		ft_putchar_fd(chr, 1);
		return (1);
	}
	if (c == 'p')
	{
		ptr = va_arg(*args, void *);
		ft_print_ptr((unsigned long long)ptr);
		return (1);
	}
	return (0);
}

static int	ft_print_ptr(unsigned long long addr)
{
	int	len;

	len = write(1, "0x", 2);
	len += ft_putnbr_base_fd(addr, "0123456789abcdef", 1);
	return (len);
}
