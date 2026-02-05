/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:37:17 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 15:24:04 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# define FILE_PATH "maps/map_120x20"

typedef struct s_coordinates
{
	int				x;
	int				y;
}					t_coordinates;

typedef struct s_map
{
	int				rows;
	int				cols;
	char			empty;
	char			obstacle;
	char			full;
	char			**grid;
	t_coordinates	coordinates;
	int				sq_size;
}					t_map;

int					ft_map_load(t_map *m, const char *pathfile);

#endif
