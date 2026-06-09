/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 08:18:03 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/09 08:09:25 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(const char *stash);
static char	*ft_get_rest(const char *stash);
static char	*ft_read_to_stash(int fd, char *stash);
static char	*ft_read_loop(int fd, char *stash, char *buffer);

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*line;
	static char	*stash;

	stash = ft_read_to_stash(fd, stash);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_get_line(stash);
	tmp = stash;
	stash = ft_get_rest(stash);
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
