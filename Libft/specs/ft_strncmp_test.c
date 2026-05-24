#include "greatest.h"
#include "../libft.h"

TEST	test_equal(void)
{
	ASSERT_EQ(0, ft_strncmp("abc", "abc", 3));
	ASSERT_EQ(0, ft_strncmp("hello", "hello", 5));
	PASS();
}

TEST	test_different(void)
{
	ASSERT(ft_strncmp("abc", "abd", 3) < 0);
	ASSERT(ft_strncmp("abd", "abc", 3) > 0);
	PASS();
}

TEST	test_zero_n(void)
{
	ASSERT_EQ(0, ft_strncmp("abc", "xyz", 0));
	PASS();
}

TEST	test_prefix(void)
{
	ASSERT_EQ(0, ft_strncmp("abc", "abcdef", 3));
	PASS();
}

TEST	test_shorter_string(void)
{
	ASSERT(ft_strncmp("ab", "abc", 3) < 0);
	ASSERT(ft_strncmp("abc", "ab", 3) > 0);
	PASS();
}

SUITE(suite_strncmp)
{
	RUN_TEST(test_equal);
	RUN_TEST(test_different);
	RUN_TEST(test_zero_n);
	RUN_TEST(test_prefix);
	RUN_TEST(test_shorter_string);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strncmp);
	GREATEST_MAIN_END();
}
