/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 10:18:42 by dieandra          #+#    #+#             */
/*   Updated: 2026/02/01 21:03:37 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <dict.h>

# define MAX_LEN 256
# define MAX_ENTRIES 100
# define BUFFER_SIZE 1024

int		ft_is_numeric(const char *str);
int		is_zero(char *s);
int		ft_is_zero_str(char *s);
int		is_float(char *str);
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_process_args(char *num, char *dict_path, t_entry *dict);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_trim(char *str);
char	*ft_strtok(char *str, const char *delim);
char	*ft_create_power(int digit);

// --- Gerenciamento de Memória
char	*ft_strdup(char *src);
char	*ft_join(char *a, char *b);
void	*ft_memcpy(void *dst, void *src, unsigned int size);
char	*ft_convert_number(char *nbr, t_entry *dict, int size);

#endif