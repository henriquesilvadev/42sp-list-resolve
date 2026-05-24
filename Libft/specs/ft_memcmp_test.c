/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 16:26:38 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/24 16:26:47 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_equal(void)
{
	ASSERT_EQ(0, ft_memcmp("Hello", "Hello", 5));
	ASSERT_EQ(0, ft_memcmp("abc", "abc", 3));
	ASSERT_EQ(0, ft_memcmp("test", "test", 4));
	PASS();
}

TEST	test_different(void)
{
	ASSERT(ft_memcmp("abc", "abd", 3) < 0);
	ASSERT(ft_memcmp("abd", "abc", 3) > 0);
	ASSERT(ft_memcmp("b", "a", 1) > 0);
	PASS();
}

TEST	test_partial(void)
{
	ASSERT_EQ(0, ft_memcmp("abcXXX", "abcYYY", 3));
	ASSERT(ft_memcmp("abcXXX", "abcYYY", 4) < 0);
	PASS();
}

TEST	test_zero_n(void)
{
	ASSERT_EQ(0, ft_memcmp("abc", "xyz", 0));
	ASSERT_EQ(0, ft_memcmp("", "", 0));
	PASS();
}

TEST	test_null_bytes(void)
{
	ASSERT_EQ(0, ft_memcmp("a\0b", "a\0b", 3));
	ASSERT(ft_memcmp("a\0b", "a\0c", 3) < 0);
	PASS();
}

TEST	test_unsigned_comparison(void)
{
	unsigned char	s1[1] = {200};
	unsigned char	s2[1] = {100};

	ASSERT(ft_memcmp(s1, s2, 1) > 0);
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT_EQ(0, ft_memcmp("a", "a", 1));
	ASSERT(ft_memcmp("a", "b", 1) < 0);
	ASSERT(ft_memcmp("b", "a", 1) > 0);
	PASS();
}

SUITE(suite_memcmp)
{
	RUN_TEST(test_equal);
	RUN_TEST(test_different);
	RUN_TEST(test_partial);
	RUN_TEST(test_zero_n);
	RUN_TEST(test_null_bytes);
	RUN_TEST(test_unsigned_comparison);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_memcmp);
	GREATEST_MAIN_END();
}
