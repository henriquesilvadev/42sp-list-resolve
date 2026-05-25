/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 08:12:49 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 08:12:58 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "libft.h"

static void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

static void	to_lower(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

static void	alternate_case(unsigned int i, char *c)
{
	if (i % 2 == 0 && *c >= 'a' && *c <= 'z')
		*c -= 32;
	else if (i % 2 != 0 && *c >= 'A' && *c <= 'Z')
		*c += 32;
}

static void	add_index(unsigned int i, char *c)
{
	*c += (char)i;
}

static void	do_nothing(unsigned int i, char *c)
{
	(void)i;
	(void)c;
}

TEST	test_to_upper(void)
{
	char	s1[] = "hello";
	char	s2[] = "Hello World";
	char	s3[] = "12345";

	ft_striteri(s1, to_upper);
	ASSERT_STR_EQ("HELLO", s1);
	ft_striteri(s2, to_upper);
	ASSERT_STR_EQ("HELLO WORLD", s2);
	ft_striteri(s3, to_upper);
	ASSERT_STR_EQ("12345", s3);
	PASS();
}

TEST	test_to_lower(void)
{
	char	s1[] = "WORLD";
	char	s2[] = "HELLO WORLD";

	ft_striteri(s1, to_lower);
	ASSERT_STR_EQ("world", s1);
	ft_striteri(s2, to_lower);
	ASSERT_STR_EQ("hello world", s2);
	PASS();
}

TEST	test_do_nothing(void)
{
	char	s[] = "abcdef";

	ft_striteri(s, do_nothing);
	ASSERT_STR_EQ("abcdef", s);
	PASS();
}

TEST	test_index_aware(void)
{
	char	s1[] = "abcdef";
	char	s2[] = "ABCDEF";
	char	s3[] = "aaa";

	ft_striteri(s1, alternate_case);
	ASSERT_STR_EQ("AbCdEf", s1);
	ft_striteri(s2, alternate_case);
	ASSERT_STR_EQ("AbCdEf", s2);
	/* 'a'(97)+0, 'a'+1, 'a'+2 => 'a','b','c' */
	ft_striteri(s3, add_index);
	ASSERT_STR_EQ("abc", s3);
	PASS();
}

TEST	test_empty_string(void)
{
	char	s[] = "";

	ft_striteri(s, to_upper);
	ASSERT_STR_EQ("", s);
	PASS();
}

TEST	test_single_char(void)
{
	char	s1[] = "z";
	char	s2[] = "A";

	ft_striteri(s1, to_upper);
	ASSERT_STR_EQ("Z", s1);
	ft_striteri(s2, to_lower);
	ASSERT_STR_EQ("a", s2);
	PASS();
}

TEST	test_special_chars(void)
{
	char	s1[] = "a b!c";
	char	s2[] = "!@#$%";

	ft_striteri(s1, to_upper);
	ASSERT_STR_EQ("A B!C", s1);
	ft_striteri(s2, do_nothing);
	ASSERT_STR_EQ("!@#$%", s2);
	PASS();
}

TEST	test_modifies_in_place(void)
{
	char	s[] = "hello";
	char	*ptr = s;

	ft_striteri(s, to_upper);
	ASSERT(s == ptr);
	ASSERT_STR_EQ("HELLO", s);
	PASS();
}

SUITE(suite_striteri)
{
	RUN_TEST(test_to_upper);
	RUN_TEST(test_to_lower);
	RUN_TEST(test_do_nothing);
	RUN_TEST(test_index_aware);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_single_char);
	RUN_TEST(test_special_chars);
	RUN_TEST(test_modifies_in_place);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_striteri);
	GREATEST_MAIN_END();
}
