/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:31:52 by hhonorio          #+#    #+#             */
/*   Updated: 2026/02/01 18:33:42 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# define MAX_LEN 256
# define MAX_ENTRIES 100
# define BUFFER_SIZE 1024

typedef struct s_entry
{
	char	key[MAX_LEN];
	char	value[MAX_LEN];
}	t_entry;

typedef struct s_dict
{
	t_entry	*items;
	int		len;
	int		cap;
}	t_dict;

int		ft_dict_load(t_entry *d, const char *pathfile);
char	*ft_dict_get(t_entry *d, int size, const char *key);

#endif