/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 17:17:10 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/26 15:32:50 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <complex.h>

static int	word_counts(const char *str, char c);
static char	**free_str(char **str, size_t j, int check);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**str;

	str = malloc(sizeof(char *) * (word_counts(s, c) + 1));
	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			return (free_str(str, j, 1));
		start = i;
		while (s[i] != c && s[i])
			i++;
		str[j++] = ft_substr(s, start, (i - start));
		if (!str[j - 1])
			return (free_str(str, j, 1));
	}
	str[j] = NULL;
	return (str);
}

static int	word_counts(const char *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**free_str(char **str, size_t j, int check)
{
	if (check)
	{
		while (j--)
			free(str[j]);
		free(str);
	}
	return (NULL);
}
