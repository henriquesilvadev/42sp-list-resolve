#include "greatest.h"
#include "../libft.h"

TEST	test_positive(void)
{
	ASSERT_EQ(0, ft_atoi("0"));
	ASSERT_EQ(42, ft_atoi("42"));
	ASSERT_EQ(123, ft_atoi("123"));
	PASS();
}

TEST	test_negative(void)
{
	ASSERT_EQ(-1, ft_atoi("-1"));
	ASSERT_EQ(-42, ft_atoi("-42"));
	ASSERT_EQ(-100, ft_atoi("-100"));
	PASS();
}

TEST	test_whitespace_prefix(void)
{
	ASSERT_EQ(42, ft_atoi("   42"));
	ASSERT_EQ(-5, ft_atoi("\t\n-5"));
	ASSERT_EQ(0, ft_atoi("  0"));
	PASS();
}

TEST	test_sign(void)
{
	ASSERT_EQ(42, ft_atoi("+42"));
	ASSERT_EQ(-42, ft_atoi("-42"));
	PASS();
}

TEST	test_non_digit_stops(void)
{
	ASSERT_EQ(42, ft_atoi("42abc"));
	ASSERT_EQ(0, ft_atoi("abc"));
	PASS();
}

SUITE(suite_atoi)
{
	RUN_TEST(test_positive);
	RUN_TEST(test_negative);
	RUN_TEST(test_whitespace_prefix);
	RUN_TEST(test_sign);
	RUN_TEST(test_non_digit_stops);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_atoi);
	GREATEST_MAIN_END();
}
