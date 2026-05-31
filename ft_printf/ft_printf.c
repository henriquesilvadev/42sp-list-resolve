/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:12:20 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/31 08:06:52 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	b_count;
	va_list	args;

	i = 0;
	b_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			b_count += handle_conversion(format[i + 1], &args);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			b_count++;
		}
		i++;
	}
	va_end(args);
	return (b_count);
}
