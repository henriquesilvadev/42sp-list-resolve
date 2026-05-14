/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 12:21:32 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 19:44:21 by fsayuri-         ###   ########.fr       */
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

int	ft_parse_header(t_map *m, char *line)
{
	int	i;
	int	rows;

	if (!m || !line)
		return (0);
	i = 0;
	while (line[i])
		i++;
	if (i < 4)
		return (0);
	rows = ft_atoi(line, i - 3);
	if (rows == -1)
		return (0);
	m->rows = rows;
	m->empty = line[i - 3];
	m->obstacle = line[i - 2];
	m->full = line[i - 1];
	if (m->empty == m->obstacle || m->empty == m->full
		|| m->obstacle == m->full)
		return (0);
	if (!ft_is_printable(m->full) || !ft_is_printable(m->obstacle)
		|| !ft_is_printable(m->empty))
		return (0);
	return (1);
}
