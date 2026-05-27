/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 09:36:03 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/27 08:46:53 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long nbr);

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = (long)n;
	if (nb < 0)
		nb = -nb;
	len = count_digits(nb) + (n < 0);
	str = malloc(len + 1);
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

	if (nbr == 0)
		return (1);
	count = 0;
	if (nbr > 0)
		nbr = -nbr;
	while (nbr != 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}
