#include "greatest.h"
#include "../libft.h"

TEST	test_uppercase_converted(void)
{
	ASSERT_EQ('a', ft_tolower('A'));
	ASSERT_EQ('z', ft_tolower('Z'));
	ASSERT_EQ('m', ft_tolower('M'));
	PASS();
}

TEST	test_lowercase_unchanged(void)
{
	ASSERT_EQ('a', ft_tolower('a'));
	ASSERT_EQ('z', ft_tolower('z'));
	PASS();
}

TEST	test_non_alpha_unchanged(void)
{
	ASSERT_EQ('0', ft_tolower('0'));
	ASSERT_EQ('!', ft_tolower('!'));
	ASSERT_EQ(' ', ft_tolower(' '));
	PASS();
}

SUITE(suite_tolower)
{
	RUN_TEST(test_uppercase_converted);
	RUN_TEST(test_lowercase_unchanged);
	RUN_TEST(test_non_alpha_unchanged);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_tolower);
	GREATEST_MAIN_END();
}
