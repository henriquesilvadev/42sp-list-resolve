#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"

TEST	test_lowercase_zero(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%x", 0u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("0", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_lowercase_single(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%x", 10u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("a", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_lowercase_ff(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%x", 255u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("ff", buf);
	ASSERT_EQ(2, ret);
	PASS();
}

TEST	test_lowercase_deadbeef(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%x", 0xdeadbeef);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("deadbeef", buf);
	ASSERT_EQ(8, ret);
	PASS();
}

TEST	test_uppercase_zero(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%X", 0u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("0", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_uppercase_FF(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%X", 255u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("FF", buf);
	ASSERT_EQ(2, ret);
	PASS();
}

TEST	test_uppercase_DEADBEEF(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%X", 0xdeadbeef);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("DEADBEEF", buf);
	ASSERT_EQ(8, ret);
	PASS();
}

TEST	test_lowercase_16(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("%x", 16u);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("10", buf);
	ASSERT_EQ(2, ret);
	PASS();
}

SUITE(suite_hex)
{
	RUN_TEST(test_lowercase_zero);
	RUN_TEST(test_lowercase_single);
	RUN_TEST(test_lowercase_ff);
	RUN_TEST(test_lowercase_deadbeef);
	RUN_TEST(test_uppercase_zero);
	RUN_TEST(test_uppercase_FF);
	RUN_TEST(test_uppercase_DEADBEEF);
	RUN_TEST(test_lowercase_16);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_hex);
	GREATEST_MAIN_END();
}
