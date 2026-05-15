/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:32:30 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/15 16:32:45 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;
	char			*last;

	i = 0;
	last = NULL;
	uc = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == uc)
			last = (char *)&s[i];
		if (uc == '\0')
			return ((char *)&s[i]);
		i++;
	}
	return (last);
}
