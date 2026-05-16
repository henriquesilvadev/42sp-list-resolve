/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:42:43 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/16 14:44:48 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*memset(void *s, int c, size_t n)
{
	unsigned char	s_byte;

	s_byte = (unsigned char)*s;
	while (n > 0)
	{
		s_byte++;
		n--;
	}
}
