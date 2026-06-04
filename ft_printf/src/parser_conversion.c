/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 10:20:13 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/04 09:01:32 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_conversion	while_conversion(\
		const char *format, \
		t_conversion conv, \
		size_t *i);

t_conversion	parser_conversion(const char *format, size_t *i)
{			
	t_conversion	conv;

	conv.flag = '\0';
	conv.width = 0;
	conv.precision = 0;
	conv.precision_set = false;
	conv.specifier = '\0';
	return (while_conversion(format, conv, i));
}

static t_conversion	while_conversion(\
		const char *format, \
		t_conversion conv, \
		size_t *i)
{
	while (format[*i])
	{
		if (format[*i] == '-' || format[*i] == '0')
		{
			if (format[*i] == '-')
				conv.flag |= FLAG_MINUS;
			else
				conv.flag |= FLAG_ZERO;
		}
		if (format[*i] == '.')
			conv.precision_set = true;
		if (ft_isdigit(format[*i]) && !conv.precision_set)
			conv.width = conv.width * 10 + (format[*i] - '0');
		if (ft_isdigit(format[*i]) && conv.precision_set)
			conv.precision = conv.precision * 10 + (format[*i] - '0');
		if (ft_isalpha(format[*i]) || format[*i] == '%')
		{
			conv.specifier = format[*i];
			break ;
		}
		(*i)++;
	}
	return (conv);
}
