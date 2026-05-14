/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:05:39 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/13 13:15:21 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	int fd;
	int bytes;
	char buffer[1];

	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}

	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);

	bytes = read(fd, buffer, 1);
	while (bytes > 0)
	{
		write (1, buffer, bytes);
		bytes = read(fd, buffer, 1);
	}
	close (fd);

	return (0);
}
