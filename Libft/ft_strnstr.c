/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 09:04:31 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/18 11:35:50 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)(haystack + i));
		}
		i++;
		j = 0;
	}
	return (NULL);
}

int	main(void)
{
	printf("%s\n", ft_strnstr("MESTRE", "EST", 6));
	printf("%s\n", ft_strnstr("MESTRE", "EST", 2));
	printf("%s\n", ft_strnstr("MESTRE", "XYZ", 6));
	printf("%s\n", ft_strnstr("MESTRE", "MESTRE", 6));
	printf("%s\n", ft_strnstr("", "EST", 6));
	printf("%s\n", ft_strnstr("MESTRE", "RE", 6));
}
