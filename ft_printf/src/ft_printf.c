/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 09:12:20 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/04 12:42:54 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	size_t			i;
	size_t			b_count;
	va_list			args;

	i = 0;
	b_count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == INIT_FLAG)
			b_count += handle_conversion(format[++i], &args);
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
