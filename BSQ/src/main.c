/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 08:40:04 by hhonorio          #+#    #+#             */
/*   Updated: 2026/02/04 19:16:43 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <library.h>
#include <map.h>

void	process_map(t_map m)
{
	ft_best_square_tracker(&m);
	ft_print_solution(m);
	ft_map_free(&m);
}

void	ft_print_one_map(t_map *map)
{
	if (!ft_map_load(map, 0))
	{
		write(1, "map error\n", 10);
		return ;
	}
	process_map(*map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	if (argc == 1)
	{
		ft_print_one_map(&map);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (i != 1)
			write(1, "\n", 1);
		if (!ft_map_load(&map, argv[i]))
		{
			write(1, "map error\n", 10);
			i++;
			continue ;
		}
		process_map(map);
		i++;
	}
	return (0);
}
