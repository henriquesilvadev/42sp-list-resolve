#include "greatest.h"
#include "../libft.h"

TEST	test_found(void)
{
	char	buf[6] = "hello";

	ASSERT(ft_memchr(buf, 'e', 5) == (void *)(buf + 1));
	ASSERT(ft_memchr(buf, 'h', 5) == (void *)(buf));
	PASS();
}

TEST	test_not_found(void)
{
	char	buf[6] = "hello";

	ASSERT(ft_memchr(buf, 'z', 5) == NULL);
	PASS();
}

TEST	test_limited_search(void)
{
	char	buf[6] = "hello";

	ASSERT(ft_memchr(buf, 'o', 3) == NULL);
	ASSERT(ft_memchr(buf, 'o', 5) == (void *)(buf + 4));
	PASS();
}

TEST	test_zero_len(void)
{
	char	buf[4] = "abc";

	ASSERT(ft_memchr(buf, 'a', 0) == NULL);
	PASS();
}

SUITE(suite_memchr)
{
	RUN_TEST(test_found);
	RUN_TEST(test_not_found);
	RUN_TEST(test_limited_search);
	RUN_TEST(test_zero_len);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_memchr);
	GREATEST_MAIN_END();
}
