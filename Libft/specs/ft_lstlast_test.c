/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 08:09:44 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/26 08:09:51 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_valid(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	c = ft_lstnew("c");
	a->next = b;
	b->next = c;
	ASSERT_EQ(ft_lstlast(a), c);
	free(a);
	free(b);
	free(c);
	PASS();
}

TEST	test_invalid(void)
{
	ASSERT_EQ(ft_lstlast(NULL), NULL);
	PASS();
}

TEST	test_boundaries(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew("a");
	ASSERT_EQ(ft_lstlast(a), a);
	b = ft_lstnew("b");
	a->next = b;
	ASSERT_EQ(ft_lstlast(a), b);
	c = ft_lstnew("c");
	b->next = c;
	ASSERT_EQ(ft_lstlast(a), c);
	ASSERT_EQ(ft_lstlast(b), c);
	ASSERT_EQ(ft_lstlast(c), c);
	free(a);
	free(b);
	free(c);
	PASS();
}

SUITE(suite_lstlast)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstlast);
	GREATEST_MAIN_END();
}
