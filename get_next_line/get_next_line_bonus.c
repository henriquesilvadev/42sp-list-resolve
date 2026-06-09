/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 08:18:03 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/09 10:33:46 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(const char *stash);
static char	*ft_get_rest(const char *stash);
static char	*ft_read_to_stash(int fd, char *stash);
static char	*ft_read_loop(int fd, char *stash, char *buffer);

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	static char	*stash[OPEN_MAX];

	stash[fd] = ft_read_to_stash(fd, stash[fd]);
	if (!stash[fd] || !*stash[fd])
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_get_line(stash[fd]);
	tmp = stash[fd];
	stash[fd] = ft_get_rest(stash[fd]);
	free(tmp);
	return (line);
}

static char	*ft_get_line(const char *stash)
{
	size_t	i;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash, i);
	line[i] = '\0';
	return (line);
}

static	char	*ft_get_rest(const char *stash)
{
	size_t	i;
	size_t	len;
	char	*line;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (NULL);
	i++;
	len = ft_strlen(stash + i);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, stash + i, len);
	line[len] = '\0';
	return (line);
}

static char	*ft_read_to_stash(int fd, char *stash)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(stash);
		return (NULL);
	}
	stash = ft_read_loop(fd, stash, buffer);
	free(buffer);
	return (stash);
}

static char	*ft_read_loop(int fd, char *stash, char *buffer)
{
	ssize_t	rd;
	char	*tmp;

	while (!ft_strchr(stash, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free(stash);
			return (NULL);
		}
		if (rd == 0)
			break ;
		buffer[rd] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buffer);
		free(tmp);
	}
	return (stash);
}
