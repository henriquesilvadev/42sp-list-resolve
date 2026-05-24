#include "greatest.h"
#include "../libft.h"

TEST	test_positive(void)
{
	char	*s;

	s = ft_itoa(42);
	ASSERT(s != NULL);
	ASSERT_STR_EQ("42", s);
	free(s);
	s = ft_itoa(0);
	ASSERT_STR_EQ("0", s);
	free(s);
	PASS();
}

TEST	test_negative(void)
{
	char	*s;

	s = ft_itoa(-42);
	ASSERT(s != NULL);
	ASSERT_STR_EQ("-42", s);
	free(s);
	s = ft_itoa(-1);
	ASSERT_STR_EQ("-1", s);
	free(s);
	PASS();
}

TEST	test_limits(void)
{
	char	*s;

	s = ft_itoa(2147483647);
	ASSERT_STR_EQ("2147483647", s);
	free(s);
	s = ft_itoa(-2147483648);
	ASSERT_STR_EQ("-2147483648", s);
	free(s);
	PASS();
}

SUITE(suite_itoa)
{
	RUN_TEST(test_positive);
	RUN_TEST(test_negative);
	RUN_TEST(test_limits);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_itoa);
	GREATEST_MAIN_END();
}
