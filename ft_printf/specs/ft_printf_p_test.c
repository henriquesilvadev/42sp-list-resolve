#include "greatest.h"
#include "capture.h"
#include "../libftprintf.h"
#include <string.h>

TEST	test_starts_with_0x(void)
{
	char	buf[32];
	int		*ptr;

	ptr = (int *)0x1;
	capture_start();
	ft_printf("%p", (void *)ptr);
	capture_end(buf, sizeof(buf));
	ASSERT(buf[0] == '0' && buf[1] == 'x');
	PASS();
}

TEST	test_known_address(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%p", (void *)0xff);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("0xff", buf);
	ASSERT_EQ(4, ret);
	PASS();
}

TEST	test_return_value(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%p", (void *)0xdeadbeef);
	capture_end(buf, sizeof(buf));
	ASSERT_EQ((int)strlen(buf), ret);
	PASS();
}

TEST	test_small_address(void)
{
	char	buf[32];
	int		ret;

	capture_start();
	ret = ft_printf("%p", (void *)0x1);
	capture_end(buf, sizeof(buf));
	ASSERT_STR_EQ("0x1", buf);
	ASSERT_EQ(3, ret);
	PASS();
}

SUITE(suite_p)
{
	RUN_TEST(test_starts_with_0x);
	RUN_TEST(test_known_address);
	RUN_TEST(test_return_value);
	RUN_TEST(test_small_address);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_p);
	GREATEST_MAIN_END();
}
