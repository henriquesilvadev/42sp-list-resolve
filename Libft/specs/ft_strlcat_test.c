/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:59:22 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/24 14:59:42 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_basic_concat(void)
{
	char	dst[20] = "Hello";

	ASSERT_EQ(11, ft_strlcat(dst, " World", 20));
	ASSERT_STR_EQ("Hello World", dst);
	PASS();
}

TEST	test_truncation(void)
{
	char	dst[10] = "Hello";

	ASSERT_EQ(11, ft_strlcat(dst, " World", 8));
	ASSERT_STR_EQ("Hello W", dst);
	PASS();
}

TEST	test_null_terminator(void)
{
	char	dst[10] = "Hi";

	ft_strlcat(dst, "!!!!", 10);
	ASSERT_EQ('\0', dst[6]);
	PASS();
}

TEST	test_empty_dst(void)
{
	char	dst[20] = "";

	ASSERT_EQ(5, ft_strlcat(dst, "Hello", 20));
	ASSERT_STR_EQ("Hello", dst);
	PASS();
}

TEST	test_empty_src(void)
{
	char	dst[20] = "Hello";

	ASSERT_EQ(5, ft_strlcat(dst, "", 20));
	ASSERT_STR_EQ("Hello", dst);
	PASS();
}

TEST	test_dstsize_too_small(void)
{
	char	dst[20] = "Hello";

	ASSERT_EQ(11, ft_strlcat(dst, " World", 3));
	ASSERT_STR_EQ("Hello", dst);
	PASS();
}

TEST	test_exact_size(void)
{
	char	dst[12] = "Hello";

	ASSERT_EQ(11, ft_strlcat(dst, " World", 12));
	ASSERT_STR_EQ("Hello World", dst);
	ASSERT_EQ('\0', dst[11]);
	PASS();
}

TEST	test_return_value(void)
{
	char	dst[5] = "Hi";
	size_t	ret;

	ret = ft_strlcat(dst, "Hello", 5);
	ASSERT_EQ(7, ret);
	PASS();
}

SUITE(suite_strlcat)
{
	RUN_TEST(test_basic_concat);
	RUN_TEST(test_truncation);
	RUN_TEST(test_null_terminator);
	RUN_TEST(test_empty_dst);
	RUN_TEST(test_empty_src);
	RUN_TEST(test_dstsize_too_small);
	RUN_TEST(test_exact_size);
	RUN_TEST(test_return_value);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strlcat);
	GREATEST_MAIN_END();
}
