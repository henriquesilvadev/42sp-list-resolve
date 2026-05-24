#include "greatest.h"
#include "../libft.h"

TEST	test_found(void)
{
	const char	*s = "hello";

	ASSERT(ft_strchr(s, 'e') == s + 1);
	ASSERT(ft_strchr(s, 'h') == s);
	PASS();
}

TEST	test_not_found(void)
{
	ASSERT(ft_strchr("hello", 'z') == NULL);
	PASS();
}

TEST	test_null_terminator(void)
{
	const char	*s = "hello";

	ASSERT(ft_strchr(s, '\0') == s + 5);
	PASS();
}

TEST	test_first_occurrence(void)
{
	const char	*s = "abcabc";

	ASSERT(ft_strchr(s, 'a') == s);
	PASS();
}

SUITE(suite_strchr)
{
	RUN_TEST(test_found);
	RUN_TEST(test_not_found);
	RUN_TEST(test_null_terminator);
	RUN_TEST(test_first_occurrence);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strchr);
	GREATEST_MAIN_END();
}
