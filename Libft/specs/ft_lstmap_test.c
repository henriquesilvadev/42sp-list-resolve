/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:02:56 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/26 11:03:05 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

static void	*to_upper(void *content)
{
	char	*str;
	char	*new;
	int		i;

	str = (char *)content;
	new = ft_strdup(str);
	i = 0;
	while (new[i])
	{
		new[i] = ft_toupper(new[i]);
		i++;
	}
	return (new);
}

static void	del(void *content)
{
	free(content);
}

TEST	test_valid(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;
	t_list	*result;

	a = ft_lstnew(ft_strdup("hello"));
	b = ft_lstnew(ft_strdup("world"));
	c = ft_lstnew(ft_strdup("42"));
	a->next = b;
	b->next = c;
	result = ft_lstmap(a, to_upper, del);
	ASSERT_STR_EQ((char *)result->content, "HELLO");
	ASSERT_STR_EQ((char *)result->next->content, "WORLD");
	ASSERT_STR_EQ((char *)result->next->next->content, "42");
	ASSERT_EQ(ft_lstsize(result), 3);
	ft_lstclear(&result, del);
	ft_lstclear(&a, del);
	PASS();
}

TEST	test_invalid(void)
{
	t_list	*result;

	result = ft_lstmap(NULL, to_upper, del);
	ASSERT_EQ(result, NULL);
	PASS();
}

TEST	test_boundaries(void)
{
	t_list	*a;
	t_list	*result;

	a = ft_lstnew(ft_strdup("hello"));
	result = ft_lstmap(a, to_upper, del);
	ASSERT_STR_EQ((char *)result->content, "HELLO");
	ASSERT_EQ(ft_lstsize(result), 1);
	ASSERT_EQ(result->next, NULL);
	ft_lstclear(&result, del);
	ft_lstclear(&a, del);
	PASS();
}

SUITE(suite_lstmap)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstmap);
	GREATEST_MAIN_END();
}
