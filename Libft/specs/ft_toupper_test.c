#include "greatest.h"
#include "../libft.h"

TEST	test_lowercase_converted(void)
{
	ASSERT_EQ('A', ft_toupper('a'));
	ASSERT_EQ('Z', ft_toupper('z'));
	ASSERT_EQ('M', ft_toupper('m'));
	PASS();
}

TEST	test_uppercase_unchanged(void)
{
	ASSERT_EQ('A', ft_toupper('A'));
	ASSERT_EQ('Z', ft_toupper('Z'));
	PASS();
}

TEST	test_non_alpha_unchanged(void)
{
	ASSERT_EQ('0', ft_toupper('0'));
	ASSERT_EQ('!', ft_toupper('!'));
	ASSERT_EQ(' ', ft_toupper(' '));
	PASS();
}

SUITE(suite_toupper)
{
	RUN_TEST(test_lowercase_converted);
	RUN_TEST(test_uppercase_unchanged);
	RUN_TEST(test_non_alpha_unchanged);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_toupper);
	GREATEST_MAIN_END();
}
