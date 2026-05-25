/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:02:36 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 09:23:47 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_simple_char(void)
{
	int		fd;
	char	buf[2];

	fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('A', fd);
	close(fd);
	fd = open("/tmp/test_putchar", O_RDONLY);
	read(fd, buf, 1);
	buf[1] = '\0';
	close(fd);
	ASSERT_EQ('A', buf[0]);
	PASS();
}

TEST	test_lowercase(void)
{
	int		fd;
	char	buf[2];

	fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('z', fd);
	close(fd);
	fd = open("/tmp/test_putchar", O_RDONLY);
	read(fd, buf, 1);
	buf[1] = '\0';
	close(fd);
	ASSERT_EQ('z', buf[0]);
	PASS();
}

TEST	test_digit(void)
{
	int		fd;
	char	buf[2];

	fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('4', fd);
	close(fd);
	fd = open("/tmp/test_putchar", O_RDONLY);
	read(fd, buf, 1);
	buf[1] = '\0';
	close(fd);
	ASSERT_EQ('4', buf[0]);
	PASS();
}

TEST	test_special_char(void)
{
	int		fd;
	char	buf[2];

	fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('!', fd);
	close(fd);
	fd = open("/tmp/test_putchar", O_RDONLY);
	read(fd, buf, 1);
	buf[1] = '\0';
	close(fd);
	ASSERT_EQ('!', buf[0]);
	PASS();
}

TEST	test_newline(void)
{
	int		fd;
	char	buf[2];

	fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('\n', fd);
	close(fd);
	fd = open("/tmp/test_putchar", O_RDONLY);
	read(fd, buf, 1);
	buf[1] = '\0';
	close(fd);
	ASSERT_EQ('\n', buf[0]);
	PASS();
}

TEST	test_space(void)
{
	int		fd;
	char	buf[2];

	fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd(' ', fd);
	close(fd);
	fd = open("/tmp/test_putchar", O_RDONLY);
	read(fd, buf, 1);
	buf[1] = '\0';
	close(fd);
	ASSERT_EQ(' ', buf[0]);
	PASS();
}

TEST	test_only_one_char_written(void)
{
	int		fd;
	char	buf[4];
	int		bytes;

	fd = open("/tmp/test_putchar", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('X', fd);
	close(fd);
	fd = open("/tmp/test_putchar", O_RDONLY);
	bytes = read(fd, buf, 3);
	close(fd);
	ASSERT_EQ(1, bytes);
	PASS();
}

SUITE(suite_putchar_fd)
{
	RUN_TEST(test_simple_char);
	RUN_TEST(test_lowercase);
	RUN_TEST(test_digit);
	RUN_TEST(test_special_char);
	RUN_TEST(test_newline);
	RUN_TEST(test_space);
	RUN_TEST(test_only_one_char_written);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_putchar_fd);
	GREATEST_MAIN_END();
}
