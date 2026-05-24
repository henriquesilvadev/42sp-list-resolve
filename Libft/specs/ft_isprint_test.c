#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	ASSERT(ft_isprint(' '));
	ASSERT(ft_isprint('A'));
	ASSERT(ft_isprint('~'));
	ASSERT(ft_isprint('0'));
	ASSERT(ft_isprint('!'));
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_FALSE(ft_isprint('\0'));
	ASSERT_FALSE(ft_isprint('\n'));
	ASSERT_FALSE(ft_isprint('\t'));
	ASSERT_FALSE(ft_isprint(127));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_isprint(32));
	ASSERT(ft_isprint(126));
	ASSERT_FALSE(ft_isprint(31));
	ASSERT_FALSE(ft_isprint(127));
	PASS();
}

SUITE(suite_isprint)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_isprint);
	GREATEST_MAIN_END();
}
