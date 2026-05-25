/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 15:06:25 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 15:07:28 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_add_to_empty_list(void)
{
	t_list	*lst = NULL;
	t_list	*node = ft_lstnew("A");

	ft_lstadd_front(&lst, node);
	ASSERT_EQ(lst, node);
	ASSERT_EQ(lst->next, NULL);
	ASSERT_EQ(lst->content, (void *)"A");
	PASS();
}

TEST	test_add_to_one_element_list(void)
{
	t_list	*lst = ft_lstnew("B");
	t_list	*node = ft_lstnew("A");

	ft_lstadd_front(&lst, node);
	ASSERT_EQ(lst, node);
	ASSERT_EQ(lst->next->content, (void *)"B");
	ASSERT_EQ(lst->next->next, NULL);
	PASS();
}

TEST	test_add_to_multiple_elements(void)
{
	t_list	*c = ft_lstnew("C");
	t_list	*b = ft_lstnew("B");
	t_list	*node = ft_lstnew("A");

	b->next = c;
	t_list	*lst = b;
	ft_lstadd_front(&lst, node);
	ASSERT_EQ(lst, node);
	ASSERT_EQ(lst->next, b);
	ASSERT_EQ(lst->next->next, c);
	ASSERT_EQ(lst->next->next->next, NULL);
	PASS();
}

TEST	test_next_not_overwritten_with_null(void)
{
	t_list	*lst = ft_lstnew("X");
	t_list	*node = ft_lstnew("Y");

	ft_lstadd_front(&lst, node);
	ASSERT_NEQ(node->next, NULL);
	PASS();
}

TEST	test_successive_inserts_lifo_order(void)
{
	t_list	*lst = NULL;
	t_list	*n1 = ft_lstnew("1");
	t_list	*n2 = ft_lstnew("2");
	t_list	*n3 = ft_lstnew("3");

	ft_lstadd_front(&lst, n1);
	ft_lstadd_front(&lst, n2);
	ft_lstadd_front(&lst, n3);
	ASSERT_EQ(lst, n3);
	ASSERT_EQ(lst->next, n2);
	ASSERT_EQ(lst->next->next, n1);
	ASSERT_EQ(lst->next->next->next, NULL);
	PASS();
}

SUITE(suite_lstadd_front)
{
	RUN_TEST(test_add_to_empty_list);
	RUN_TEST(test_add_to_one_element_list);
	RUN_TEST(test_add_to_multiple_elements);
	RUN_TEST(test_next_not_overwritten_with_null);
	RUN_TEST(test_successive_inserts_lifo_order);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstadd_front);
	GREATEST_MAIN_END();
}
