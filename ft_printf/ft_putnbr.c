/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:46:56 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/31 12:06:50 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_count(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	if (n < 0)
	{
		ft_putstr_fd("-", 1);
		len++;
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr_count(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putnbr_unsigned(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}
