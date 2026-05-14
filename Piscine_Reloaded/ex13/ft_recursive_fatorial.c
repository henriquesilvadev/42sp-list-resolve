/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_fatorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 07:35:47 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/13 07:41:47 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_fatorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * ft_recursive_fatorial(nb - 1));
}
