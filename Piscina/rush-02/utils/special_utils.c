/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:34:12 by dieandra          #+#    #+#             */
/*   Updated: 2026/02/01 21:08:03 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*ft_strtok(char *str, const char *delim)
{
	static char	*last;
	char		*start;
	int			i;

	if (str)
		last = str;
	if (!last)
		return (0);
	i = 0;
	while (last[i] && ft_strchr(delim, last[i]))
		i++;
	if (!last[i])
		return (last = 0);
	start = &last[i];
	while (last[i] && !ft_strchr(delim, last[i]))
		i++;
	if (last[i])
	{
		last[i] = '\0';
		last = &last[i + 1];
	}
	else
		last = 0;
	return (start);
}

int	ft_is_zero_str(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
