/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 07:21:17 by hhonorio          #+#    #+#             */
/*   Updated: 2026/01/22 10:48:07 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	print_solution(int board[10])
{
	int		row;
	char	c;

	row = 0;
	while (row < 10)
	{
		c = board[row] + '0';
		ft_putchar(c);
		row++;
	}
	ft_putchar('\n');
}

int	is_safe(int board[10], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i] == col)
			return (0);
		if (ft_abs(board[i] - col) == ft_abs(i - row))
			return (0);
		i++;
	}
	return (1);
}

void	solve(int board[10], int row, int *count)
{
	int	col;

	if (row == 10)
	{
		print_solution(board);
		(*count)++;
		return ;
	}
	col = 0;
	while (col < 10)
	{
		if (is_safe(board, row, col))
		{
			board[row] = col;
			solve(board, row + 1, count);
		}
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	solve(board, 0, &count);
	return (count);
}

int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
