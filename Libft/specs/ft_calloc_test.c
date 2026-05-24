#include "greatest.h"
#include "../libft.h"

TEST	test_allocates_zeroed(void)
{
	unsigned char	*p;
	size_t			i;

	p = ft_calloc(8, 1);
	ASSERT(p != NULL);
	i = 0;
	while (i < 8)
		ASSERT_EQ(0, p[i++]);
	free(p);
	PASS();
}

TEST	test_zero_nmemb(void)
{
	void	*p;

	p = ft_calloc(0, 4);
	free(p);
	PASS();
}

TEST	test_correct_size(void)
{
	int	*p;

	p = ft_calloc(5, sizeof(int));
	ASSERT(p != NULL);
	ASSERT_EQ(0, p[0]);
	ASSERT_EQ(0, p[4]);
	free(p);
	PASS();
}

SUITE(suite_calloc)
{
	RUN_TEST(test_allocates_zeroed);
	RUN_TEST(test_zero_nmemb);
	RUN_TEST(test_correct_size);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_calloc);
	GREATEST_MAIN_END();
}
