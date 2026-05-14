/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:19:46 by hhonorio          #+#    #+#             */
/*   Updated: 2026/02/01 21:19:14 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

#define MAX_ENTRIES 100
#define MAX_LEN 256
#define BUFFER_SIZE 1024

int	ft_fill_entry(t_entry *entry, char *line)
{
	char	*sep;
	char	*key;
	char	*val;

	sep = ft_strchr(line, ':');
	if (!sep)
		return (0);
	*sep = '\0';
	key = ft_trim(line);
	val = ft_trim(sep + 1);
	if (*key == '\0' || *val == '\0' || ft_is_numeric(key) == 0)
		return (0);
	ft_strcpy(entry->key, key);
	ft_strcpy(entry->value, val);
	return (1);
}

int	ft_dict_load(t_entry *d, const char *pathfile)
{
	int		fd;
	int		count;
	int		b_read;
	char	buffer[BUFFER_SIZE];
	char	*line;

	fd = open(pathfile, O_RDONLY);
	if (fd == -1)
		return (-1);
	b_read = read(fd, buffer, BUFFER_SIZE - 1);
	close(fd);
	if (b_read <= 0)
		return (-1);
	buffer[b_read] = '\0';
	count = 0;
	line = ft_strtok(buffer, "\n");
	while (line != NULL && count < MAX_ENTRIES)
	{
		if (ft_fill_entry(&d[count], line))
			count++;
		line = ft_strtok(NULL, "\n");
	}
	return (count);
}

char	*ft_dict_get(t_entry *d, int size, const char *key)
{
	int	i;

	i = 0;
	if (!d || !key || size <= 0)
		return (NULL);
	while (i < size)
	{
		if (ft_strcmp(d[i].key, key) == 0)
			return (d[i].value);
		i++;
	}
	return (NULL);
}
