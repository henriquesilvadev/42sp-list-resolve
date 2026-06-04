/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:00:30 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/27 11:01:19 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, const char *set);

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	j--;
	while (s1[i] && is_charset(s1[i], set))
		i++;
	if (i > j)
		return (ft_strdup(""));
	while (j >= i && is_charset(s1[j], set))
		j--;
	len = j - i + 1;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	len = 0;
	while (i <= j)
		str[len++] = s1[i++];
	str[len] = '\0';
	return (str);
}

static int	is_charset(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
