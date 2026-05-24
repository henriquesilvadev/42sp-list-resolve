#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	ASSERT(ft_isspace(' '));
	ASSERT(ft_isspace('\t'));
	ASSERT(ft_isspace('\n'));
	ASSERT(ft_isspace('\r'));
	ASSERT(ft_isspace('\v'));
	ASSERT(ft_isspace('\f'));
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_FALSE(ft_isspace('a'));
	ASSERT_FALSE(ft_isspace('0'));
	ASSERT_FALSE(ft_isspace('!'));
	ASSERT_FALSE(ft_isspace('\0'));
	PASS();
}

TEST	test_boundaries(void)
{
	ASSERT(ft_isspace(9));
	ASSERT(ft_isspace(13));
	ASSERT(ft_isspace(32));
	ASSERT_FALSE(ft_isspace(8));
	ASSERT_FALSE(ft_isspace(14));
	PASS();
}

SUITE(suite_isspace)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_isspace);
	GREATEST_MAIN_END();
}
