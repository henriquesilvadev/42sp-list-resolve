/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 17:25:29 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/24 17:25:45 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

static void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

TEST	test_basic(void)
{
	char	**result;

	result = ft_split("hello world foo", ' ');
	ASSERT_STR_EQ("hello", result[0]);
	ASSERT_STR_EQ("world", result[1]);
	ASSERT_STR_EQ("foo", result[2]);
	ASSERT_EQ(NULL, result[3]);
	free_split(result);
	PASS();
}

TEST	test_multiple_delimiters(void)
{
	char	**result;

	result = ft_split("hello:::world", ':');
	ASSERT_STR_EQ("hello", result[0]);
	ASSERT_STR_EQ("world", result[1]);
	ASSERT_EQ(NULL, result[2]);
	free_split(result);
	PASS();
}

TEST	test_delimiter_at_start_and_end(void)
{
	char	**result;

	result = ft_split("  hello  ", ' ');
	ASSERT_STR_EQ("hello", result[0]);
	ASSERT_EQ(NULL, result[1]);
	free_split(result);
	PASS();
}

TEST	test_empty_string(void)
{
	char	**result;

	result = ft_split("", ' ');
	ASSERT_EQ(NULL, result[0]);
	free_split(result);
	PASS();
}

TEST	test_no_delimiter(void)
{
	char	**result;

	result = ft_split("hello", ' ');
	ASSERT_STR_EQ("hello", result[0]);
	ASSERT_EQ(NULL, result[1]);
	free_split(result);
	PASS();
}

TEST	test_only_delimiters(void)
{
	char	**result;

	result = ft_split("   ", ' ');
	ASSERT_EQ(NULL, result[0]);
	free_split(result);
	PASS();
}

TEST	test_single_char(void)
{
	char	**result;

	result = ft_split("a", ' ');
	ASSERT_STR_EQ("a", result[0]);
	ASSERT_EQ(NULL, result[1]);
	free_split(result);
	PASS();
}

TEST	test_single_char_delimiter(void)
{
	char	**result;

	result = ft_split("a b c d", ' ');
	ASSERT_STR_EQ("a", result[0]);
	ASSERT_STR_EQ("b", result[1]);
	ASSERT_STR_EQ("c", result[2]);
	ASSERT_STR_EQ("d", result[3]);
	ASSERT_EQ(NULL, result[4]);
	free_split(result);
	PASS();
}

SUITE(suite_split)
{
	RUN_TEST(test_basic);
	RUN_TEST(test_multiple_delimiters);
	RUN_TEST(test_delimiter_at_start_and_end);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_no_delimiter);
	RUN_TEST(test_only_delimiters);
	RUN_TEST(test_single_char);
	RUN_TEST(test_single_char_delimiter);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_split);
	GREATEST_MAIN_END();
}
