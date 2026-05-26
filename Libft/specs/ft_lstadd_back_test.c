/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 08:46:20 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/26 08:46:28 by hhonorio         ###   ########.fr       */
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
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	ASSERT_EQ(ft_lstlast(a), c);
	ASSERT_EQ(ft_lstsize(a), 3);
	free(a);
	free(b);
	free(c);
	PASS();
}

TEST	test_invalid(void)
{
	t_list	*lst;
	t_list	*a;

	lst = NULL;
	a = ft_lstnew("a");
	ft_lstadd_back(&lst, a);
	ASSERT_EQ(lst, a);
	ASSERT_EQ(ft_lstsize(lst), 1);
	free(a);
	PASS();
}

TEST	test_boundaries(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew("a");
	b = ft_lstnew("b");
	ft_lstadd_back(&a, b);
	ASSERT_EQ(ft_lstlast(a), b);
	ASSERT_EQ(ft_lstsize(a), 2);
	c = ft_lstnew("c");
	ft_lstadd_back(&a, c);
	ASSERT_EQ(ft_lstlast(a), c);
	ASSERT_EQ(ft_lstsize(a), 3);
	ASSERT_EQ(a->next, b);
	ASSERT_EQ(b->next, c);
	free(a);
	free(b);
	free(c);
	PASS();
}

SUITE(suite_lstadd_back)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstadd_back);
	GREATEST_MAIN_END();
}
