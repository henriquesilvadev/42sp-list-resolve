/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:58:29 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/26 09:58:35 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

static void	del(void *content)
{
	free(content);
}

TEST	test_valid(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew(ft_strdup("a"));
	b = ft_lstnew(ft_strdup("b"));
	c = ft_lstnew(ft_strdup("c"));
	a->next = b;
	b->next = c;
	ft_lstclear(&a, del);
	ASSERT_EQ(a, NULL);
	PASS();
}

TEST	test_invalid(void)
{
	t_list	*lst;

	lst = NULL;
	ft_lstclear(&lst, del);
	ASSERT_EQ(lst, NULL);
	PASS();
}

TEST	test_boundaries(void)
{
	t_list	*a;

	a = ft_lstnew(ft_strdup("a"));
	ft_lstclear(&a, del);
	ASSERT_EQ(a, NULL);
	PASS();
}

SUITE(suite_lstclear)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstclear);
	GREATEST_MAIN_END();
}
