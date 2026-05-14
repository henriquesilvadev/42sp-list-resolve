/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:40:45 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 19:37:43 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <fcntl.h>
# include <map.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
int		ft_parse_header(t_map *m, char *line);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strtok(char *str, const char *delim);

char	*ft_strdup(char *src);

void	ft_best_square_tracker(t_map *m);
int		**ft_create_matrix(int rows, int cols);
int		get_min_value(int a, int b, int c);
void	ft_clean_matrix(int **board, int cols);
void	ft_print_solution(t_map m);
void	ft_map_free(t_map *m);
int		ft_parse_grid(t_map *m, char *line);
int		ft_atoi(char *num, int nb);
int		ft_is_printable(char str);

#endif