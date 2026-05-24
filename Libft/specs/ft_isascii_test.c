#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	ASSERT(ft_isascii(0));
	ASSERT(ft_isascii(65));
	ASSERT(ft_isascii(127));
	ASSERT(ft_isascii('A'));
	ASSERT(ft_isascii(' '));
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_FALSE(ft_isascii(-1));
	ASSERT_FALSE(ft_isascii(128));
	ASSERT_FALSE(ft_isascii(255));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_isascii(0));
	ASSERT(ft_isascii(127));
	ASSERT_FALSE(ft_isascii(-1));
	ASSERT_FALSE(ft_isascii(128));
	PASS();
}

SUITE(suite_isascii)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_isascii);
	GREATEST_MAIN_END();
}
