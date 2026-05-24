#include "greatest.h"
#include "../libft.h"

TEST	test_last_occurrence(void)
{
	const char	*s = "abcabc";

	ASSERT(ft_strrchr(s, 'a') == s + 3);
	ASSERT(ft_strrchr(s, 'c') == s + 5);
	PASS();
}

TEST	test_not_found(void)
{
	ASSERT(ft_strrchr("hello", 'z') == NULL);
	PASS();
}

TEST	test_null_terminator(void)
{
	const char	*s = "hello";

	ASSERT(ft_strrchr(s, '\0') == s + 5);
	PASS();
}

TEST	test_single_char(void)
{
	const char	*s = "a";

	ASSERT(ft_strrchr(s, 'a') == s);
	PASS();
}

SUITE(suite_strrchr)
{
	RUN_TEST(test_last_occurrence);
	RUN_TEST(test_not_found);
	RUN_TEST(test_null_terminator);
	RUN_TEST(test_single_char);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_strrchr);
	GREATEST_MAIN_END();
}
