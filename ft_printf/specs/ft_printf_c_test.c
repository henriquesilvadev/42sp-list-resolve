#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"

TEST	test_uppercase(void)
{
	char	buf[4];
	int		ret;

	capture_start();
	ret = ft_printf("%c", 'A');
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("A", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_lowercase(void)
{
	char	buf[4];
	int		ret;

	capture_start();
	ret = ft_printf("%c", 'z');
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("z", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_digit(void)
{
	char	buf[4];
	int		ret;

	capture_start();
	ret = ft_printf("%c", '9');
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("9", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_space(void)
{
	char	buf[4];
	int		ret;

	capture_start();
	ret = ft_printf("%c", ' ');
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ(" ", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_special(void)
{
	char	buf[4];
	int		ret;

	capture_start();
	ret = ft_printf("%c", '!');
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("!", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

TEST	test_newline(void)
{
	char	buf[4];
	int		ret;

	capture_start();
	ret = ft_printf("%c", '\n');
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("\n", buf);
	ASSERT_EQ(1, ret);
	PASS();
}

SUITE(suite_c)
{
	RUN_TEST(test_uppercase);
	RUN_TEST(test_lowercase);
	RUN_TEST(test_digit);
	RUN_TEST(test_space);
	RUN_TEST(test_special);
	RUN_TEST(test_newline);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_c);
	GREATEST_MAIN_END();
}
