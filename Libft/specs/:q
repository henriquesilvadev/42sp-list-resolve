#include "greatest.h"
#include "../libft.h"

TEST	test_fills_bytes(void)
{
	char	buf[5];

	ft_memset(buf, 'X', 5);
	ASSERT_EQ('X', buf[0]);
	ASSERT_EQ('X', buf[4]);
	PASS();
}

TEST	test_returns_ptr(void)
{
	char	buf[4];

	ASSERT(ft_memset(buf, 0, 4) == (void *)buf);
	PASS();
}

TEST	test_partial(void)
{
	char	buf[6];
	int		i;

	ft_memset(buf, 0, 6);
	ft_memset(buf, 'A', 3);
	i = 0;
	while (i < 3)
		ASSERT_EQ('A', buf[i++]);
	ASSERT_EQ(0, buf[3]);
	PASS();
}

TEST	test_zero_len(void)
{
	char	buf[4];

	ft_memset(buf, 'Z', 4);
	ft_memset(buf, 0, 0);
	ASSERT_EQ('Z', buf[0]);
	PASS();
}

SUITE(suite_memset)
{
	RUN_TEST(test_fills_bytes);
	RUN_TEST(test_returns_ptr);
	RUN_TEST(test_partial);
	RUN_TEST(test_zero_len);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_memset);
	GREATEST_MAIN_END();
}
