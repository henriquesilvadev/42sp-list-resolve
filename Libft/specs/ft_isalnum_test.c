/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 08:47:07 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/24 09:09:07 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	ASSERT(ft_isalnum('0'));
	ASSERT(ft_isalnum('5'));
	ASSERT(ft_isalnum('9'));
	ASSERT(ft_isalnum('A'));
	ASSERT(ft_isalnum('G'));
	ASSERT(ft_isalnum('D'));
	ASSERT(ft_isalnum('a'));
	ASSERT(ft_isalnum('f'));
	ASSERT(ft_isalnum('x'));
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_FALSE(ft_isalnum(' '));
	ASSERT_FALSE(ft_isalnum('\t'));
	ASSERT_FALSE(ft_isalnum('\n'));
	ASSERT_FALSE(ft_isalnum('!'));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_isalnum('0'));
	ASSERT(ft_isalnum('9'));
	ASSERT(ft_isalnum('a'));
	ASSERT(ft_isalnum('z'));
	ASSERT(ft_isalnum('A'));
	ASSERT(ft_isalnum('Z'));
	ASSERT_FALSE(ft_isalnum('/'));
	ASSERT_FALSE(ft_isalnum(':'));
	PASS();
}

SUITE(suite_isalnum)
{
    RUN_TEST(test_valid);
    RUN_TEST(test_invalid);
    RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_isalnum);
	GREATEST_MAIN_END();
}
