/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:26:03 by hhonorio          #+#    #+#             */
/*   Updated: 2026/01/21 19:58:00 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	temp;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	temp = nb;
	while (power > 1)
	{
		nb *= temp;
		power--;
	}
	return (nb);
}
