/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 07:38:39 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 07:39:07 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "libft.h"

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

static char	to_lower(unsigned int i, char c)
{
	(void)i;
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

static char	alternate_case(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return (c - 32);
	if (i % 2 != 0 && c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

static char	add_index(unsigned int i, char c)
{
	return (c + (char)i);
}

static char	always_x(unsigned int i, char c)
{
	(void)i;
	(void)c;
	return ('X');
}

static char	identity(unsigned int i, char c)
{
	(void)i;
	return (c);
}

TEST	test_to_upper(void)
{
	char	*result;

	result = ft_strmapi("hello", to_upper);
	ASSERT_STR_EQ("HELLO", result);
	free(result);
	result = ft_strmapi("Hello World", to_upper);
	ASSERT_STR_EQ("HELLO WORLD", result);
	free(result);
	result = ft_strmapi("12345", to_upper);
	ASSERT_STR_EQ("12345", result);
	free(result);
	PASS();
}

TEST	test_to_lower(void)
{
	char	*result;

	result = ft_strmapi("WORLD", to_lower);
	ASSERT_STR_EQ("world", result);
	free(result);
	result = ft_strmapi("HELLO WORLD", to_lower);
	ASSERT_STR_EQ("hello world", result);
	free(result);
	PASS();
}

TEST	test_identity(void)
{
	char	*result;

	result = ft_strmapi("abcdef", identity);
	ASSERT_STR_EQ("abcdef", result);
	free(result);
	result = ft_strmapi("Hello, 42!", identity);
	ASSERT_STR_EQ("Hello, 42!", result);
	free(result);
	PASS();
}

TEST	test_index_aware(void)
{
	char	*result;

	result = ft_strmapi("abcdef", alternate_case);
	ASSERT_STR_EQ("AbCdEf", result);
	free(result);
	result = ft_strmapi("ABCDEF", alternate_case);
	ASSERT_STR_EQ("AbCdEf", result);
	free(result);
	result = ft_strmapi("aaa", add_index);
	ASSERT_STR_EQ("abc", result);
	free(result);
	PASS();
}

TEST	test_always_x(void)
{
	char	*result;

	result = ft_strmapi("hello", always_x);
	ASSERT_STR_EQ("XXXXX", result);
	free(result);
	result = ft_strmapi("42", always_x);
	ASSERT_STR_EQ("XX", result);
	free(result);
	PASS();
}

TEST	test_empty_string(void)
{
	char	*result;

	result = ft_strmapi("", to_upper);
	ASSERT(result != NULL);
	ASSERT_STR_EQ("", result);
	free(result);
	PASS();
}

TEST	test_single_char(void)
{
	char	*result;

	result = ft_strmapi("z", to_upper);
	ASSERT_STR_EQ("Z", result);
	free(result);
	result = ft_strmapi("A", to_lower);
	ASSERT_STR_EQ("a", result);
	free(result);
	PASS();
}

TEST	test_special_chars(void)
{
	char	*result;

	result = ft_strmapi("a b!c", to_upper);
	ASSERT_STR_EQ("A B!C", result);
	free(result);
	result = ft_strmapi("!@#$%", identity);
	ASSERT_STR_EQ("!@#$%", result);
	free(result);
	PASS();
}

TEST	test_new_allocation(void)
{
	const char	*src = "teste";
	char		*result;

	result = ft_strmapi(src, identity);
	ASSERT(result != NULL);
	ASSERT(result != src);
	ASSERT_EQ((int)strlen(src), (int)strlen(result));
	free(result);
	PASS();
}

SUITE(suite_strmapi)
{
	RUN_TEST(test_to_upper);
	RUN_TEST(test_to_lower);
	RUN_TEST(test_identity);
	RUN_TEST(test_index_aware);
	RUN_TEST(test_always_x);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_single_char);
	RUN_TEST(test_special_chars);
	RUN_TEST(test_new_allocation);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strmapi);
	GREATEST_MAIN_END();
}
