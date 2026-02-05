/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:28:23 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 16:14:49 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

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

void	ft_map_free(t_map *m)
{
	int	i;

	if (!m)
		return ;
	if (m->grid)
	{
		i = 0;
		while (i < m->rows)
		{
			free(m->grid[i]);
			m->grid[i] = NULL;
			i++;
		}
		free(m->grid);
		m->grid = NULL;
	}
	m->rows = 0;
	m->cols = 0;
}
