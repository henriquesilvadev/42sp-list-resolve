#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"

TEST	test_positive(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%d", 42);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("42", buf);
	ASSERT_EQ(2, ret);
	PASS();
}

TEST	test_negative(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%d", -1);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("-1", buf);
	ASSERT_EQ(2, ret);
	PASS();
}

TEST	test_zero(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%d", 0);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("0", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_single_digit(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%d", 7);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("7", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_int_max(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%d", 2147483647);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("2147483647", buf);
	ASSERT_EQ(10, ret);
	PASS();
}

TEST	test_int_min(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%d", -2147483648);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("-2147483648", buf);
	ASSERT_EQ(11, ret);
	PASS();
}

SUITE(suite_d)
{
	RUN_TEST(test_positive);
	RUN_TEST(test_negative);
	RUN_TEST(test_zero);
	RUN_TEST(test_single_digit);
	RUN_TEST(test_int_max);
	RUN_TEST(test_int_min);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_d);
	GREATEST_MAIN_END();
}
