#include "greatest.h"
#include "../libft.h"
#include <string.h>

TEST	test_no_overlap(void)
{
	char	src[6] = "hello";
	char	dst[6];

	ft_memmove(dst, src, 6);
	ASSERT_EQ(0, memcmp(dst, "hello", 6));
	PASS();
}

TEST	test_returns_dst(void)
{
	char	buf[8] = "hello";

	ASSERT(ft_memmove(buf, buf + 1, 4) == (void *)buf);
	PASS();
}

TEST	test_overlap_forward(void)
{
	char	buf[8] = "abcdef";

	ft_memmove(buf + 2, buf, 4);
	ASSERT_EQ(0, memcmp(buf + 2, "abcd", 4));
	PASS();
}

TEST	test_zero_len(void)
{
	char	src[4] = "abc";
	char	dst[4];

	memset(dst, 'X', 4);
	ft_memmove(dst, src, 0);
	ASSERT_EQ('X', dst[0]);
	PASS();
}

SUITE(suite_memmove)
{
	RUN_TEST(test_no_overlap);
	RUN_TEST(test_returns_dst);
	RUN_TEST(test_overlap_forward);
	RUN_TEST(test_zero_len);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_memmove);
	GREATEST_MAIN_END();
}
