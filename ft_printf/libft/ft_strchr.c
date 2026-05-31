/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 14:07:15 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/18 13:03:08 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	unsigned char	uc;

	uc = (unsigned char) c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == uc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == uc)
		return ((char *) &s[i]);
	return (NULL);
}
