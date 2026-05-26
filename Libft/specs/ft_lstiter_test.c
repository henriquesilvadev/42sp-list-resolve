/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 10:40:43 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/26 10:40:51 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../libft.h"

static void	to_upper(void *content)
{
	char	*str;
	int		i;

	str = (char *)content;
	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

TEST	test_valid(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = ft_lstnew(ft_strdup("hello"));
	b = ft_lstnew(ft_strdup("world"));
	c = ft_lstnew(ft_strdup("42"));
	a->next = b;
	b->next = c;
	ft_lstiter(a, to_upper);
	ASSERT_STR_EQ((char *)a->content, "HELLO");
	ASSERT_STR_EQ((char *)b->content, "WORLD");
	ASSERT_STR_EQ((char *)c->content, "42");
	free(a->content);
	free(b->content);
	free(c->content);
	free(a);
	free(b);
	free(c);
	PASS();
}

TEST	test_invalid(void)
{
	ft_lstiter(NULL, to_upper);
	PASS();
}

TEST	test_boundaries(void)
{
	t_list	*a;

	a = ft_lstnew(ft_strdup("hello"));
	ft_lstiter(a, to_upper);
	ASSERT_STR_EQ((char *)a->content, "HELLO");
	free(a->content);
	free(a);
	PASS();
}

SUITE(suite_lstiter)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstiter);
	GREATEST_MAIN_END();
}
