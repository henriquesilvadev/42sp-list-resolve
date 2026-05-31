#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"

TEST	test_normal_string(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%s", "hello");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("hello", buf);
	ASSERT_EQ(5, ret);
	PASS();
}

TEST	test_empty_string(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%s", "");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("", buf);
	ASSERT_EQ(0, ret);
	PASS();
}

TEST	test_null_pointer(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%s", (char *)NULL);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("(null)", buf);
	ASSERT_EQ(6, ret);
	PASS();
}

TEST	test_single_char(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%s", "x");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("x", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_string_with_spaces(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%s", "hello world");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("hello world", buf);
	ASSERT_EQ(11, ret);
	PASS();
}

SUITE(suite_s)
{
	RUN_TEST(test_normal_string);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_null_pointer);
	RUN_TEST(test_single_char);
	RUN_TEST(test_string_with_spaces);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_s);
	GREATEST_MAIN_END();
}
