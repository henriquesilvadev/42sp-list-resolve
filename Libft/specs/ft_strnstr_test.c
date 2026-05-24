#include "greatest.h"
#include "../libft.h"

TEST	test_found(void)
{
	const char	*h = "hello world";

	ASSERT(ft_strnstr(h, "world", 11) == h + 6);
	ASSERT(ft_strnstr(h, "hello", 11) == h);
	PASS();
}

TEST	test_not_found(void)
{
	ASSERT(ft_strnstr("hello", "world", 5) == NULL);
	PASS();
}

TEST	test_empty_needle(void)
{
	const char	*h = "hello";

	ASSERT(ft_strnstr(h, "", 5) == h);
	PASS();
}

TEST	test_limited_len(void)
{
	ASSERT(ft_strnstr("hello world", "world", 8) == NULL);
	PASS();
}

TEST	test_needle_longer_than_len(void)
{
	ASSERT(ft_strnstr("hi", "hello", 2) == NULL);
	PASS();
}

SUITE(suite_strnstr)
{
	RUN_TEST(test_found);
	RUN_TEST(test_not_found);
	RUN_TEST(test_empty_needle);
	RUN_TEST(test_limited_len);
	RUN_TEST(test_needle_longer_than_len);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strnstr);
	GREATEST_MAIN_END();
}
