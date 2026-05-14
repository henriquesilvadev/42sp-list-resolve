/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 15:48:48 by dieandra          #+#    #+#             */
/*   Updated: 2026/02/01 21:07:55 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*ft_memcpy(void *dst, void *src, unsigned int size)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (size)
	{
		*d++ = *s++;
		size--;
	}
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*str;
	int		i;

	i = ft_strlen(s);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}

char	*ft_join(char *a, char *b)
{
	char	*res;
	int		len_a;
	int		len_b;

	if (!a && !b)
		return (NULL);
	if (!a)
		return (ft_strdup(b));
	if (!b)
		return (ft_strdup(a));
	len_a = ft_strlen(a);
	len_b = ft_strlen(b);
	res = malloc(len_a + len_b + 2);
	if (!res)
		return (NULL);
	ft_strcpy(res, a);
	res[len_a] = ' ';
	ft_strcpy(res + len_a + 1, b);
	return (res);
}
