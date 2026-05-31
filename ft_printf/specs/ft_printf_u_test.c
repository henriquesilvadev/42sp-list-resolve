#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"

TEST	test_positive(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%u", 42u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("42", buf);
	ASSERT_EQ(2, ret);
	PASS();
}

TEST	test_zero(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%u", 0u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("0", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_large(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%u", 123456789u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("123456789", buf);
	ASSERT_EQ(9, ret);
	PASS();
}

TEST	test_uint_max(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%u", 4294967295u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("4294967295", buf);
	ASSERT_EQ(10, ret);
	PASS();
}

TEST	test_single_digit(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%u", 5u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("5", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

SUITE(suite_u)
{
	RUN_TEST(test_positive);
	RUN_TEST(test_zero);
	RUN_TEST(test_large);
	RUN_TEST(test_uint_max);
	RUN_TEST(test_single_digit);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_u);
	GREATEST_MAIN_END();
}
