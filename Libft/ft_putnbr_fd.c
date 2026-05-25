/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:33:38 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 10:45:26 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <complex.h>
#include <wchar.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	*str_n;

	str_n = ft_itoa(n);
	ft_putstr_fd(str_n, fd);
	free(str_n);
}
