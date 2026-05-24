#include "greatest.h"
#include "../libft.h"

TEST	test_zeros_bytes(void)
{
	char	buf[8];

	memset(buf, 'A', 8);
	ft_bzero(buf, 5);
	ASSERT_EQ(0, buf[0]);
	ASSERT_EQ(0, buf[1]);
	ASSERT_EQ(0, buf[4]);
	ASSERT_EQ('A', buf[5]);
	PASS();
}

TEST	test_zero_len(void)
{
	char	buf[4];

	memset(buf, 'A', 4);
	ft_bzero(buf, 0);
	ASSERT_EQ('A', buf[0]);
	PASS();
}

TEST	test_full_buffer(void)
{
	char	buf[4];
	int		i;

	memset(buf, 'X', 4);
	ft_bzero(buf, 4);
	i = 0;
	while (i < 4)
		ASSERT_EQ(0, buf[i++]);
	PASS();
}

SUITE(suite_bzero)
{
	RUN_TEST(test_zeros_bytes);
	RUN_TEST(test_zero_len);
	RUN_TEST(test_full_buffer);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_bzero);
	GREATEST_MAIN_END();
}
