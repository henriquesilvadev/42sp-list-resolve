/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 08:17:50 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/04 09:00:55 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_base_fd(unsigned long long n, char *base, int fd)
{
	size_t	len;
	size_t	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		len += ft_putnbr_base_fd(n / base_len, base, fd);
	len += write(fd, &base[n % base_len], 1);
	return (len);
}
