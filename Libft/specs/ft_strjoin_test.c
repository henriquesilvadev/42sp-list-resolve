#include "greatest.h"
#include "../libft.h"
#include <stdlib.h>

TEST	test_join(void)
{
	char	*result;

	result = ft_strjoin("hello", " world");
	ASSERT(result != NULL);
	ASSERT_STR_EQ("hello world", result);
	free(result);
	PASS();
}

TEST	test_empty_strings(void)
{
	char	*result;

	result = ft_strjoin("", "");
	ASSERT_STR_EQ("", result);
	free(result);
	result = ft_strjoin("abc", "");
	ASSERT_STR_EQ("abc", result);
	free(result);
	result = ft_strjoin("", "abc");
	ASSERT_STR_EQ("abc", result);
	free(result);
	PASS();
}

TEST	test_null_returns_null(void)
{
	ASSERT_EQ(NULL, ft_strjoin(NULL, "abc"));
	ASSERT_EQ(NULL, ft_strjoin("abc", NULL));
	PASS();
}

SUITE(suite_strjoin)
{
	RUN_TEST(test_join);
	RUN_TEST(test_empty_strings);
	RUN_TEST(test_null_returns_null);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strjoin);
	GREATEST_MAIN_END();
}
