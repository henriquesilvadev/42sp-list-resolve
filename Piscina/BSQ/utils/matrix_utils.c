/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 10:00:53 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/03 14:05:52 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	**ft_create_matrix(int rows, int cols)
{
	int	**grid;
	int	i;

	grid = (int **)malloc(sizeof(int *) * rows);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		grid[i] = (int *)malloc(sizeof(int) * cols);
		if (!grid[i])
			return (NULL);
		i++;
	}
	return (grid);
}

void	ft_clean_matrix(int **board, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
