/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:43:57 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 09:44:11 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_simple_string(void)
{
	int		fd;
	char	buf[6];

	fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("hello", fd);
	close(fd);
	fd = open("/tmp/test_putstr", O_RDONLY);
	read(fd, buf, 5);
	buf[5] = '\0';
	close(fd);
	ASSERT_STR_EQ("hello", buf);
	PASS();
}

TEST	test_uppercase(void)
{
	int		fd;
	char	buf[6];

	fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("WORLD", fd);
	close(fd);
	fd = open("/tmp/test_putstr", O_RDONLY);
	read(fd, buf, 5);
	buf[5] = '\0';
	close(fd);
	ASSERT_STR_EQ("WORLD", buf);
	PASS();
}

TEST	test_string_with_spaces(void)
{
	int		fd;
	char	buf[12];

	fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("hello world", fd);
	close(fd);
	fd = open("/tmp/test_putstr", O_RDONLY);
	read(fd, buf, 11);
	buf[11] = '\0';
	close(fd);
	ASSERT_STR_EQ("hello world", buf);
	PASS();
}

TEST	test_string_with_newline(void)
{
	int		fd;
	char	buf[7];

	fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("hello\n", fd);
	close(fd);
	fd = open("/tmp/test_putstr", O_RDONLY);
	read(fd, buf, 6);
	buf[6] = '\0';
	close(fd);
	ASSERT_STR_EQ("hello\n", buf);
	PASS();
}

TEST	test_digits(void)
{
	int		fd;
	char	buf[6];

	fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("12345", fd);
	close(fd);
	fd = open("/tmp/test_putstr", O_RDONLY);
	read(fd, buf, 5);
	buf[5] = '\0';
	close(fd);
	ASSERT_STR_EQ("12345", buf);
	PASS();
}

TEST	test_empty_string(void)
{
	int		fd;
	char	buf[4];
	int		bytes;

	fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("", fd);
	close(fd);
	fd = open("/tmp/test_putstr", O_RDONLY);
	bytes = read(fd, buf, 3);
	close(fd);
	ASSERT_EQ(0, bytes);
	PASS();
}

TEST	test_only_correct_length_written(void)
{
	int		fd;
	char	buf[10];
	int		bytes;

	fd = open("/tmp/test_putstr", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("abc", fd);
	close(fd);
	fd = open("/tmp/test_putstr", O_RDONLY);
	bytes = read(fd, buf, 9);
	close(fd);
	ASSERT_EQ(3, bytes);
	PASS();
}

SUITE(suite_putstr_fd)
{
	RUN_TEST(test_simple_string);
	RUN_TEST(test_uppercase);
	RUN_TEST(test_string_with_spaces);
	RUN_TEST(test_string_with_newline);
	RUN_TEST(test_digits);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_only_correct_length_written);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_putstr_fd);
	GREATEST_MAIN_END();
}
