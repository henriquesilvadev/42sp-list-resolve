/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:16:02 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/24 14:16:10 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_basic_copy(void)
{
	char	dst[20];

	ASSERT_EQ(11, ft_strlcpy(dst, "Hello World", 20));
	ASSERT_STR_EQ("Hello World", dst);
	ASSERT_EQ(3, ft_strlcpy(dst, "Hi!", 20));
	ASSERT_STR_EQ("Hi!", dst);
	ASSERT_EQ(5, ft_strlcpy(dst, "abcde", 20));
	ASSERT_STR_EQ("abcde", dst);
	PASS();
}

TEST	test_truncation(void)
{
	char	dst[5];

	ASSERT_EQ(11, ft_strlcpy(dst, "Hello World", 5));
	ASSERT_STR_EQ("Hell", dst);
	ASSERT_EQ(6, ft_strlcpy(dst, "abcdef", 5));
	ASSERT_STR_EQ("abcd", dst);
	PASS();
}

TEST	test_zero_size(void)
{
	char	dst[20];

	ft_strlcpy(dst, "Hello", 20);
	ASSERT_EQ(5, ft_strlcpy(dst, "Hello", 0));
	ASSERT_STR_EQ("Hello", dst);
	PASS();
}

TEST	test_empty_src(void)
{
	char	dst[20];

	ASSERT_EQ(0, ft_strlcpy(dst, "", 20));
	ASSERT_STR_EQ("", dst);
	PASS();
}

TEST	test_null_terminator(void)
{
	char	dst[5];

	ft_strlcpy(dst, "Hello World", 5);
	ASSERT_EQ('\0', dst[4]);
	PASS();
}

TEST	test_exact_size(void)
{
	char	dst[6];

	ASSERT_EQ(5, ft_strlcpy(dst, "Hello", 6));
	ASSERT_STR_EQ("Hello", dst);
	ASSERT_EQ('\0', dst[5]);
	PASS();
}

SUITE(suite_strlcpy)
{
	RUN_TEST(test_basic_copy);
	RUN_TEST(test_truncation);
	RUN_TEST(test_zero_size);
	RUN_TEST(test_empty_src);
	RUN_TEST(test_null_terminator);
	RUN_TEST(test_exact_size);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strlcpy);
	GREATEST_MAIN_END();
}
