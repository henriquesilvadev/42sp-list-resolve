/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 08:15:13 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/24 08:46:03 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_valid_digits(void)
{
	ASSERT(ft_isdigit('0'));
	ASSERT(ft_isdigit('5'));
	ASSERT(ft_isdigit('9'));
	PASS();
}

TEST	test_non_digits(void)
{
	ASSERT_FALSE(ft_isdigit('a'));
	ASSERT_FALSE(ft_isdigit('Z'));
	ASSERT_FALSE(ft_isdigit(' '));
	ASSERT_FALSE(ft_isdigit('!'));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_isdigit('0'));
	ASSERT(ft_isdigit('9'));
	ASSERT_FALSE(ft_isdigit('/'));
	ASSERT_FALSE(ft_isdigit(':'));
	PASS();
}

TEST	test_edge_cases(void)
{
	ASSERT_FALSE(ft_isdigit(-1));
	ASSERT_FALSE(ft_isdigit(0));
	ASSERT_FALSE(ft_isdigit(128));
	PASS();
}

SUITE(suite_isdigit)
{
    RUN_TEST(test_valid_digits);
    RUN_TEST(test_non_digits);
    RUN_TEST(test_boundaries);
    RUN_TEST(test_edge_cases);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_isdigit);
	GREATEST_MAIN_END();
}
