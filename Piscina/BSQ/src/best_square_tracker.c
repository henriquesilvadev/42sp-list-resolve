/* ************************************************************************** */
/*					                                                          */
/*                                                        :::      ::::::::   */
/*   best_square_tracker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:36:51 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 15:59:42 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"
#include "map.h"

void	ft_update_max(t_map *m, int val, int i, int j)
{
	if (val > m->sq_size)
	{
		m->sq_size = val;
		m->coordinates.x = i;
		m->coordinates.y = j;
	}
}

void	ft_first_row(t_map m, int *best_square)
{
	int	i;

	i = 0;
	while (i < m.cols)
	{
		if (m.grid[0][i] == m.obstacle)
			best_square[i] = 0;
		else
			best_square[i] = 1;
		i++;
	}
}

static void	ft_compute_dp_row(t_map *m, int i, int *prev, int *cur)
{
	int	j;
	int	min_value;

	j = 0;
	while (j < m->cols)
	{
		if (m->grid[i][j] == m->obstacle)
			cur[j] = 0;
		else if (j == 0)
			cur[j] = 1;
		else
		{
			min_value = get_min_value(prev[j], prev[j - 1], cur[j - 1]);
			cur[j] = min_value + 1;
		}
		ft_update_max(m, cur[j], i, j);
		j++;
	}
}

static void	ft_track_rows_dp(t_map *m, int *prev, int *cur)
{
	int	i;
	int	*tmp;

	i = 1;
	while (i < m->rows)
	{
		ft_compute_dp_row(m, i, prev, cur);
		tmp = prev;
		prev = cur;
		cur = tmp;
		i++;
	}
}

void	ft_best_square_tracker(t_map *m)
{
	int	*prev;
	int	*cur;

	prev = (int *)malloc(m->cols * sizeof(int));
	cur = (int *)malloc(m->cols * sizeof(int));
	if (!prev || !cur)
		return (free(prev), free(cur));
	ft_first_row(*m, prev);
	m->sq_size = 0;
	ft_track_rows_dp(m, prev, cur);
	free(prev);
	free(cur);
}
