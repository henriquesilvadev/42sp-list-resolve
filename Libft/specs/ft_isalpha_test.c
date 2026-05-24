#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	ASSERT(ft_isalpha('a'));
	ASSERT(ft_isalpha('z'));
	ASSERT(ft_isalpha('A'));
	ASSERT(ft_isalpha('Z'));
	ASSERT(ft_isalpha('m'));
	ASSERT(ft_isalpha('M'));
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_FALSE(ft_isalpha('0'));
	ASSERT_FALSE(ft_isalpha('9'));
	ASSERT_FALSE(ft_isalpha(' '));
	ASSERT_FALSE(ft_isalpha('!'));
	ASSERT_FALSE(ft_isalpha('\n'));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_isalpha('a'));
	ASSERT(ft_isalpha('z'));
	ASSERT(ft_isalpha('A'));
	ASSERT(ft_isalpha('Z'));
	ASSERT_FALSE(ft_isalpha('`'));
	ASSERT_FALSE(ft_isalpha('{'));
	ASSERT_FALSE(ft_isalpha('@'));
	ASSERT_FALSE(ft_isalpha('['));
	PASS();
}

SUITE(suite_isalpha)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_isalpha);
	GREATEST_MAIN_END();
}
