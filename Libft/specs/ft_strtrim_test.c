#include "greatest.h"
#include "../libft.h"

TEST	test_trims_both_ends(void)
{
	char	*result;

	result = ft_strtrim("  hello  ", " ");
	ASSERT(result != NULL);
	ASSERT_STR_EQ("hello", result);
	free(result);
	PASS();
}

TEST	test_trims_charset(void)
{
	char	*result;

	result = ft_strtrim("xxhelloxx", "x");
	ASSERT_STR_EQ("hello", result);
	free(result);
	PASS();
}

TEST	test_no_trim_needed(void)
{
	char	*result;

	result = ft_strtrim("hello", " ");
	ASSERT_STR_EQ("hello", result);
	free(result);
	PASS();
}

TEST	test_all_trimmed(void)
{
	char	*result;

	result = ft_strtrim("aaaa", "a");
	ASSERT_STR_EQ("", result);
	free(result);
	PASS();
}

TEST	test_empty_string(void)
{
	char	*result;

	result = ft_strtrim("", "abc");
	ASSERT_STR_EQ("", result);
	free(result);
	PASS();
}

SUITE(suite_strtrim)
{
	RUN_TEST(test_trims_both_ends);
	RUN_TEST(test_trims_charset);
	RUN_TEST(test_no_trim_needed);
	RUN_TEST(test_all_trimmed);
	RUN_TEST(test_empty_string);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strtrim);
	GREATEST_MAIN_END();
}
