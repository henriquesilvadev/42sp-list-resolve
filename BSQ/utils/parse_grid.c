/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:07:34 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 19:30:54 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	rows_validation(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	if (!m->grid || m->rows <= 0)
		return (0);
	while (i < m->rows)
	{
		j = 0;
		if (!m->grid[i])
			return (0);
		while (m->grid[i][j] != '\0')
		{
			if (m->grid[i][j] != m->empty && m->grid[i][j] != m->obstacle)
				return (0);
			j++;
		}
		if (i == 0)
			m->cols = j;
		else if (m->cols != j)
			return (0);
		i++;
	}
	return (i == m->rows);
}

int	ft_parse_grid(t_map *m, char *line)
{
	int	i;

	m->grid = (char **)malloc(sizeof(char *) * m->rows);
	if (!m->grid)
		return (0);
	i = 0;
	line = ft_strtok(NULL, "\n");
	while (line != NULL)
	{
		if (i >= m->rows)
			return (0);
		m->grid[i] = ft_strdup(line);
		if (!m->grid[i])
			return (0);
		i++;
		line = ft_strtok(NULL, "\n");
	}
	if (i == 0)
		return (0);
	if (!rows_validation(m))
		return (0);
	return (i == m->rows);
}
