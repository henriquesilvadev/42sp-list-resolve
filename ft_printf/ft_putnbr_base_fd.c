/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 08:17:50 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/31 08:23:36 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_base_fd(unsigned long long n, char *base, int fd)
{
	int	len;

	len = 0;
	if (len >= 16)
		len += ft_putnbr_base_fd(n / 16, base, fd);
	len += write(fd, &base[n % 16], 1);
	return (len);
}
