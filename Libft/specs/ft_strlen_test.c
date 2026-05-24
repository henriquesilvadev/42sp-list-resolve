#include "greatest.h"
#include "../libft.h"

TEST	test_normal(void)
{
	ASSERT_EQ(5, (int)ft_strlen("hello"));
	ASSERT_EQ(3, (int)ft_strlen("abc"));
	ASSERT_EQ(1, (int)ft_strlen("x"));
	PASS();
}

TEST	test_empty(void)
{
	ASSERT_EQ(0, (int)ft_strlen(""));
	PASS();
}

TEST	test_special_chars(void)
{
	ASSERT_EQ(3, (int)ft_strlen("a b"));
	ASSERT_EQ(4, (int)ft_strlen("a\tb\n"));
	PASS();
}

SUITE(suite_strlen)
{
	RUN_TEST(test_normal);
	RUN_TEST(test_empty);
	RUN_TEST(test_special_chars);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strlen);
	GREATEST_MAIN_END();
}
