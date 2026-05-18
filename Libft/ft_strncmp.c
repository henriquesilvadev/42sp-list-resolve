/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 08:07:03 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/18 11:04:58 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] && s2[i]) && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%d\n", ft_strncmp("MESTRE", "MESTRE", 6));
	printf("%d\n", ft_strncmp("MESTRE", "MESTRO", 6));
	printf("%d\n", ft_strncmp("MESTRO", "MESTRE", 6));
	printf("%d\n", ft_strncmp("MESTRE", "MESTRE", 3));
	printf("%d\n", ft_strncmp("ABC", "ABD", 2));
	printf("%d\n", ft_strncmp("", "", 5));
	printf("%d\n", ft_strncmp("ABC", "", 3));
}
