/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:36:03 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/23 11:24:11 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long nbr);
static char	*malloc_result(int len);

char	*ft_itoa(int n)
{
	long	nb;
	int		sign;
	int		len;
	char	*str;

	if (nb < 0)
		nb = -nb;
	len = count_digits(nb) + (n < 0);
	str = malloc_result(len);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

static int	count_digits(long nbr)
{
	int	count;

	count = 0;
	if (nbr > 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

static char	*malloc_result(int len)
{
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	return (str);
}
