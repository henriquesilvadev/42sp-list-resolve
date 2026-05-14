/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:52:52 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 15:24:50 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_is_solution(t_map m, int i, int j)
{
	if (i <= (m.coordinates.x - m.sq_size))
		return (0);
	if (i > m.coordinates.x)
		return (0);
	if (j <= (m.coordinates.y - m.sq_size))
		return (0);
	if (j > m.coordinates.y)
		return (0);
	return (1);
}

void	ft_square_one(t_map m)
{
	int	i;
	int	j;
	int	temp;

	temp = 0;
	i = 0;
	while (i < m.rows)
	{
		j = 0;
		while (j < m.cols)
		{
			if (temp == 0 && m.grid[i][j] == m.empty)
			{
				write(1, &m.full, 1);
				temp = 1;
			}
			else
				write(1, &m.grid[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_print_solution(t_map m)
{
	int	i;
	int	j;

	if (m.sq_size <= 1)
		ft_square_one(m);
	else
	{
		i = 0;
		while (i < m.rows)
		{
			j = 0;
			while (j < m.cols)
			{
				if (ft_is_solution(m, i, j))
					write(1, &m.full, 1);
				else
					write(1, &m.grid[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
}
