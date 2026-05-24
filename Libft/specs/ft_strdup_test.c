#include "greatest.h"
#include "../libft.h"
#include <stdlib.h>

TEST	test_duplicates(void)
{
	char	*dup;

	dup = ft_strdup("hello");
	ASSERT(dup != NULL);
	ASSERT_STR_EQ("hello", dup);
	free(dup);
	PASS();
}

TEST	test_empty_string(void)
{
	char	*dup;

	dup = ft_strdup("");
	ASSERT(dup != NULL);
	ASSERT_STR_EQ("", dup);
	free(dup);
	PASS();
}

TEST	test_independent_copy(void)
{
	char	*dup;
	char	src[6] = "hello";

	dup = ft_strdup(src);
	ASSERT(dup != (char *)src);
	src[0] = 'X';
	ASSERT_EQ('h', dup[0]);
	free(dup);
	PASS();
}

SUITE(suite_strdup)
{
	RUN_TEST(test_duplicates);
	RUN_TEST(test_empty_string);
	RUN_TEST(test_independent_copy);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strdup);
	GREATEST_MAIN_END();
}
