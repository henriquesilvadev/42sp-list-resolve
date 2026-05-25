/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:01:10 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 10:01:25 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_simple_string(void)
{
	int		fd;
	char	buf[7];

	fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("hello", fd);
	close(fd);
	fd = open("/tmp/test_putendl", O_RDONLY);
	read(fd, buf, 6);
	buf[6] = '\0';
	close(fd);
	ASSERT_STR_EQ("hello\n", buf);
	PASS();
}

TEST	test_uppercase(void)
{
	int		fd;
	char	buf[7];

	fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("WORLD", fd);
	close(fd);
	fd = open("/tmp/test_putendl", O_RDONLY);
	read(fd, buf, 6);
	buf[6] = '\0';
	close(fd);
	ASSERT_STR_EQ("WORLD\n", buf);
	PASS();
}

TEST	test_string_with_spaces(void)
{
	int		fd;
	char	buf[13];

	fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("hello world", fd);
	close(fd);
	fd = open("/tmp/test_putendl", O_RDONLY);
	read(fd, buf, 12);
	buf[12] = '\0';
	close(fd);
	ASSERT_STR_EQ("hello world\n", buf);
	PASS();
}

TEST	test_digits(void)
{
	int		fd;
	char	buf[7];

	fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("12345", fd);
	close(fd);
	fd = open("/tmp/test_putendl", O_RDONLY);
	read(fd, buf, 6);
	buf[6] = '\0';
	close(fd);
	ASSERT_STR_EQ("12345\n", buf);
	PASS();
}

TEST	test_empty_string(void)
{
	int		fd;
	char	buf[4];
	int		bytes;

	fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("", fd);
	close(fd);
	fd = open("/tmp/test_putendl", O_RDONLY);
	bytes = read(fd, buf, 3);
	buf[bytes] = '\0';
	close(fd);
	ASSERT_EQ(1, bytes);
	ASSERT_STR_EQ("\n", buf);
	PASS();
}

TEST	test_single_char(void)
{
	int		fd;
	char	buf[3];

	fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("A", fd);
	close(fd);
	fd = open("/tmp/test_putendl", O_RDONLY);
	read(fd, buf, 2);
	buf[2] = '\0';
	close(fd);
	ASSERT_STR_EQ("A\n", buf);
	PASS();
}

TEST	test_correct_length_written(void)
{
	int		fd;
	char	buf[10];
	int		bytes;

	fd = open("/tmp/test_putendl", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("abc", fd);
	close(fd);
	fd = open("/tmp/test_putendl", O_RDONLY);
	bytes = read(fd, buf, 9);
	close(fd);
	ASSERT_EQ(4, bytes);
	PASS();
}

SUITE(suite_putendl_fd)
{
	RUN_TEST(test_simple_string);
	RUN_TEST(test_uppercase);
	RUN_TEST(test_string_with_spaces);
	RUN_TEST(test_digits);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_single_char);
	RUN_TEST(test_correct_length_written);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_putendl_fd);
	GREATEST_MAIN_END();
}
