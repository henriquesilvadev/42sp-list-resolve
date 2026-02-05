/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsayuri- <fsayuri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 18:04:45 by fsayuri-          #+#    #+#             */
/*   Updated: 2026/02/04 17:29:52 by fsayuri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

#define BUFFER_SIZE 4096

static char	*ft_append(char *dst, int *len, char *src, int n)
{
	char	*newbuf;
	int		i;

	newbuf = (char *)malloc(*len + n + 1);
	if (!newbuf)
		return (NULL);
	i = 0;
	while (i < *len)
	{
		newbuf[i] = dst[i];
		i++;
	}
	i = 0;
	while (i < n)
	{
		newbuf[*len + i] = src[i];
		i++;
	}
	newbuf[*len + n] = '\0';
	free(dst);
	*len += n;
	return (newbuf);
}

int	ft_create_buf(char *buf)
{
	if (!buf)
		return (0);
	buf[0] = '\0';
	return (1);
}

void	ft_choose_fd_value(int *fd, const char *path)
{
	*fd = 0;
	if (path != 0)
		*fd = open(path, O_RDONLY);
}

char	*ft_read_all(const char *path)
{
	int		fd;
	int		n;
	int		len;
	char	tmp[BUFFER_SIZE];
	char	*buf;

	buf = (char *)malloc(1);
	ft_choose_fd_value(&fd, path);
	if (fd < 0)
		return (NULL);
	if (!ft_create_buf(buf))
		return (close(fd), NULL);
	len = 0;
	n = read(fd, tmp, BUFFER_SIZE);
	while (n > 0)
	{
		buf = ft_append(buf, &len, tmp, n);
		if (!buf)
			return (close(fd), NULL);
		n = read(fd, tmp, BUFFER_SIZE);
	}
	close(fd);
	if (n < 0)
		return (free(buf), NULL);
	return (buf);
}

int	ft_map_load(t_map *m, const char *pathfile)
{
	char	*content;
	char	*line;

	content = ft_read_all(pathfile);
	if (!content)
		return (0);
	line = ft_strtok(content, "\n");
	if (!line || !ft_parse_header(m, line))
		return (free(content), 0);
	if (!ft_parse_grid(m, content))
		return (free(content), 0);
	free(content);
	return (1);
}
