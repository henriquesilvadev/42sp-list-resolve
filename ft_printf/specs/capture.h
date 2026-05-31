#ifndef CAPTURE_H
# define CAPTURE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

static int	g_stdout_bak;

static void	capture_start(void)
{
	int	fd;

	fflush(NULL);
	g_stdout_bak = dup(1);
	fd = open("/tmp/ft_printf_cap", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd, 1);
	close(fd);
}

static int	capture_end(char *buf, int size)
{
	int	n;
	int	fd;

	fflush(NULL);
	dup2(g_stdout_bak, 1);
	close(g_stdout_bak);
	fd = open("/tmp/ft_printf_cap", O_RDONLY);
	n = read(fd, buf, size - 1);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	close(fd);
	return (n);
}

#endif
