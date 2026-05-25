/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:32:34 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 10:32:47 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

static void	read_file(char *buf, int size)
{
	int	fd;

	fd = open("/tmp/test_putnbr", O_RDONLY);
	read(fd, buf, size);
	buf[size] = '\0';
	close(fd);
}

static int	open_file(void)
{
	return (open("/tmp/test_putnbr", O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

TEST	test_positive(void)
{
	int		fd;
	char	buf[12];

	fd = open_file();
	ft_putnbr_fd(42, fd);
	close(fd);
	read_file(buf, 2);
	ASSERT_STR_EQ("42", buf);
	fd = open_file();
	ft_putnbr_fd(123, fd);
	close(fd);
	read_file(buf, 3);
	ASSERT_STR_EQ("123", buf);
	PASS();
}

TEST	test_negative(void)
{
	int		fd;
	char	buf[12];

	fd = open_file();
	ft_putnbr_fd(-1, fd);
	close(fd);
	read_file(buf, 2);
	ASSERT_STR_EQ("-1", buf);
	fd = open_file();
	ft_putnbr_fd(-42, fd);
	close(fd);
	read_file(buf, 3);
	ASSERT_STR_EQ("-42", buf);
	PASS();
}

TEST	test_zero(void)
{
	int		fd;
	char	buf[2];

	fd = open_file();
	ft_putnbr_fd(0, fd);
	close(fd);
	read_file(buf, 1);
	ASSERT_STR_EQ("0", buf);
	PASS();
}

TEST	test_single_digit(void)
{
	int		fd;
	char	buf[2];

	fd = open_file();
	ft_putnbr_fd(7, fd);
	close(fd);
	read_file(buf, 1);
	ASSERT_STR_EQ("7", buf);
	PASS();
}

TEST	test_int_max(void)
{
	int		fd;
	char	buf[12];

	fd = open_file();
	ft_putnbr_fd(2147483647, fd);
	close(fd);
	read_file(buf, 10);
	ASSERT_STR_EQ("2147483647", buf);
	PASS();
}

TEST	test_int_min(void)
{
	int		fd;
	char	buf[12];

	fd = open_file();
	ft_putnbr_fd(-2147483648, fd);
	close(fd);
	read_file(buf, 11);
	ASSERT_STR_EQ("-2147483648", buf);
	PASS();
}

SUITE(suite_putnbr_fd)
{
	RUN_TEST(test_positive);
	RUN_TEST(test_negative);
	RUN_TEST(test_zero);
	RUN_TEST(test_single_digit);
	RUN_TEST(test_int_max);
	RUN_TEST(test_int_min);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_putnbr_fd);
	GREATEST_MAIN_END();
}
