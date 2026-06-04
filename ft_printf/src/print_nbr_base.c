/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 08:42:43 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/04 09:44:34 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_nbr(unsigned int nbr, int upper, int base);
static int	digit_len(unsigned int nbr, unsigned int base);
static void	fill_padding(char *buffer, size_t padding, int flag);
static void	print_with_padding(char *buffer, \
									unsigned int nbr, \
									t_print_ops p_ops, \
									t_conversion conv);

int	print_nbr_base(t_conversion conv, va_list *args, int uppercase, int base)
{
	unsigned int	nbr;
	size_t			content_len;
	size_t			padding;
	char			*buffer;
	t_print_ops		p_ops;

	if (conv.width == 0)
	{
		nbr = (unsigned int)va_arg(*args, unsigned int);
		return (print_nbr(nbr, uppercase, base));
	}
	nbr = (unsigned int) va_arg(*args, unsigned int);
	content_len = digit_len(nbr, base);
	padding = conv.width - content_len;
	buffer = malloc(conv.width);
	if (!buffer)
		return (0);
	if (conv.width <= content_len)
	{
		free(buffer);
		return (content_len);
	}
	fill_padding(buffer, padding, conv.flag);
	buffer[padding] = '\0';
	p_ops.uppercase = uppercase;
	p_ops.base = base;
	print_with_padding(buffer, nbr, p_ops, conv);
	free(buffer);
	return (padding + content_len);
}

static int	print_nbr(unsigned int nbr, int upper, int base)
{
	int	len;

	len = 0;
	if (base == 10)
		len += ft_putnbr_base_fd(nbr, "0123456789", 1);
	if (base == 16)
	{
		if (upper == 1)
			len += ft_putnbr_base_fd(nbr, "0123456789ABCDEF", 1);
		else
			len += ft_putnbr_base_fd(nbr, "0123456789abcdef", 1);
	}
	return (len);
}

static int	digit_len(unsigned int nbr, unsigned int base)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr > 0)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

static void	fill_padding(char *buffer, size_t padding, int flag)
{
	if (flag & FLAG_ZERO)
		ft_memset(buffer, '0', padding);
	else
		ft_memset(buffer, ' ', padding);
}

static void	print_with_padding(char *buffer, \
		unsigned int nbr, t_print_ops p_ops, t_conversion conv)
{
	if (conv.flag & FLAG_MINUS)
	{
		print_nbr(nbr, p_ops.uppercase, p_ops.base);
		ft_putstr_fd(buffer, 1);
	}
	else
	{
		ft_putstr_fd(buffer, 1);
		print_nbr(nbr, p_ops.uppercase, p_ops.base);
	}
}
