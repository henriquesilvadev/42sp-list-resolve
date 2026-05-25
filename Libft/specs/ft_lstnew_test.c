/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 12:00:11 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/25 12:01:50 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

TEST	test_content_int(void)
{
	int		n;
	t_list	*node;

	n = 42;
	node = ft_lstnew(&n);
	ASSERT(node != NULL);
	ASSERT_EQ(42, *(int *)node->content);
	free(node);
	PASS();
}

TEST	test_content_string(void)
{
	t_list	*node;

	node = ft_lstnew("hello");
	ASSERT(node != NULL);
	ASSERT_STR_EQ("hello", (char *)node->content);
	free(node);
	PASS();
}

TEST	test_next_is_null(void)
{
	t_list	*node;

	node = ft_lstnew("test");
	ASSERT(node != NULL);
	ASSERT_EQ(NULL, node->next);
	free(node);
	PASS();
}

TEST	test_content_null(void)
{
	t_list	*node;

	node = ft_lstnew(NULL);
	ASSERT(node != NULL);
	ASSERT_EQ(NULL, node->content);
	ASSERT_EQ(NULL, node->next);
	free(node);
	PASS();
}

TEST	test_new_allocation(void)
{
	t_list	*node1;
	t_list	*node2;

	node1 = ft_lstnew("a");
	node2 = ft_lstnew("b");
	ASSERT(node1 != NULL);
	ASSERT(node2 != NULL);
	ASSERT(node1 != node2);
	free(node1);
	free(node2);
	PASS();
}

TEST	test_content_pointer_preserved(void)
{
	char	*str;
	t_list	*node;

	str = "libft";
	node = ft_lstnew(str);
	ASSERT(node != NULL);
	ASSERT_EQ(str, (char *)node->content);
	free(node);
	PASS();
}

SUITE(suite_lstnew)
{
	RUN_TEST(test_content_int);
	RUN_TEST(test_content_string);
	RUN_TEST(test_next_is_null);
	RUN_TEST(test_content_null);
	RUN_TEST(test_new_allocation);
	RUN_TEST(test_content_pointer_preserved);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstnew);
	GREATEST_MAIN_END();
}
