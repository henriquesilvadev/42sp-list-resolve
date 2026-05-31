/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:32:30 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/18 13:07:01 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	unsigned char	uc;

	if (!s)
		return (NULL);
	uc = (unsigned char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == uc)
			res = (char *) &s[i];
		i++;
	}
	if (s[i] == uc)
		res = (char *) &s[i];
	return (res);
}
