#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	ASSERT(ft_islower('a'));
	ASSERT(ft_islower('m'));
	ASSERT(ft_islower('z'));
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_FALSE(ft_islower('A'));
	ASSERT_FALSE(ft_islower('Z'));
	ASSERT_FALSE(ft_islower('0'));
	ASSERT_FALSE(ft_islower(' '));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_islower('a'));
	ASSERT(ft_islower('z'));
	ASSERT_FALSE(ft_islower('`'));
	ASSERT_FALSE(ft_islower('{'));
	PASS();
}

SUITE(suite_islower)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_islower);
	GREATEST_MAIN_END();
}
