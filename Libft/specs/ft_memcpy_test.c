#include "greatest.h"
#include "../libft.h"
#include <string.h>

TEST	test_copies_bytes(void)
{
	char	src[6] = "hello";
	char	dst[6];

	ft_memcpy(dst, src, 6);
	ASSERT_EQ(0, memcmp(dst, src, 6));
	PASS();
}

TEST	test_returns_dst(void)
{
	char	src[4] = "abc";
	char	dst[4];

	ASSERT(ft_memcpy(dst, src, 4) == (void *)dst);
	PASS();
}

TEST	test_partial_copy(void)
{
	char	src[6] = "hello";
	char	dst[6];

	memset(dst, 0, 6);
	ft_memcpy(dst, src, 3);
	ASSERT_EQ('h', dst[0]);
	ASSERT_EQ('e', dst[1]);
	ASSERT_EQ('l', dst[2]);
	ASSERT_EQ(0, dst[3]);
	PASS();
}

TEST	test_zero_len(void)
{
	char	src[4] = "abc";
	char	dst[4];

	memset(dst, 'X', 4);
	ft_memcpy(dst, src, 0);
	ASSERT_EQ('X', dst[0]);
	PASS();
}

SUITE(suite_memcpy)
{
	RUN_TEST(test_copies_bytes);
	RUN_TEST(test_returns_dst);
	RUN_TEST(test_partial_copy);
	RUN_TEST(test_zero_len);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_memcpy);
	GREATEST_MAIN_END();
}
