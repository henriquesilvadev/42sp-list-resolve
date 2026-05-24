#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	ASSERT(ft_isupper('A'));
	ASSERT(ft_isupper('M'));
	ASSERT(ft_isupper('Z'));
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_FALSE(ft_isupper('a'));
	ASSERT_FALSE(ft_isupper('z'));
	ASSERT_FALSE(ft_isupper('0'));
	ASSERT_FALSE(ft_isupper(' '));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_isupper('A'));
	ASSERT(ft_isupper('Z'));
	ASSERT_FALSE(ft_isupper('@'));
	ASSERT_FALSE(ft_isupper('['));
	PASS();
}

SUITE(suite_isupper)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_isupper);
	GREATEST_MAIN_END();
}
