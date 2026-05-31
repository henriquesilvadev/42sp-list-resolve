#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"

TEST	test_single_percent(void)
{
	char	buf[8];
	int		ret;

	capture_start();
	ret = ft_printf("%%");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("%", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_percent_in_string(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("100%%");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("100%", buf);
	ASSERT_EQ(4, ret);
	PASS();
}

TEST	test_double_percent(void)
{
	char	buf[8];
	int		ret;

	capture_start();
	ret = ft_printf("%%%%");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("%%", buf);
	ASSERT_EQ(2, ret);
	PASS();
}

TEST	test_percent_between_strings(void)
{
	char	buf[16];
	int		ret;

	capture_start();
	ret = ft_printf("a%%b");
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("a%b", buf);
	ASSERT_EQ(3, ret);
	PASS();
}

SUITE(suite_percent)
{
	RUN_TEST(test_single_percent);
	RUN_TEST(test_percent_in_string);
	RUN_TEST(test_double_percent);
	RUN_TEST(test_percent_between_strings);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_percent);
	GREATEST_MAIN_END();
}
