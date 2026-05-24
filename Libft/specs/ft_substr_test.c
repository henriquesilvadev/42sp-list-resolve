#include "greatest.h"
#include "../libft.h"

TEST	test_normal(void)
{
	char	*result;

	result = ft_substr("hello world", 6, 5);
	ASSERT(result != NULL);
	ASSERT_STR_EQ("world", result);
	free(result);
	PASS();
}

TEST	test_from_start(void)
{
	char	*result;

	result = ft_substr("hello", 0, 3);
	ASSERT_STR_EQ("hel", result);
	free(result);
	PASS();
}

TEST	test_start_beyond_length(void)
{
	char	*result;

	result = ft_substr("hello", 10, 3);
	ASSERT_STR_EQ("", result);
	free(result);
	PASS();
}

TEST	test_len_beyond_end(void)
{
	char	*result;

	result = ft_substr("hello", 3, 100);
	ASSERT_STR_EQ("lo", result);
	free(result);
	PASS();
}

TEST	test_zero_len(void)
{
	char	*result;

	result = ft_substr("hello", 0, 0);
	ASSERT_STR_EQ("", result);
	free(result);
	PASS();
}

SUITE(suite_substr)
{
	RUN_TEST(test_normal);
	RUN_TEST(test_from_start);
	RUN_TEST(test_start_beyond_length);
	RUN_TEST(test_len_beyond_end);
	RUN_TEST(test_zero_len);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_substr);
	GREATEST_MAIN_END();
}
