/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 09:38:44 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/26 09:38:59 by hhonorio         ###   ########.fr       */
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
	char	*str;

	str = ft_strdup("a");
	a = ft_lstnew(str);
	ft_lstdelone(a, del);
	PASS();
}

TEST	test_invalid(void)
{
	t_list	*a;
	t_list	*b;
	char	*str;

	str = ft_strdup("a");
	a = ft_lstnew(str);
	b = ft_lstnew("b");
	a->next = b;
	ft_lstdelone(a, del);
	ASSERT_EQ(b->content, (void *)"b");
	free(b);
	PASS();
}

TEST	test_boundaries(void)
{
	t_list	*a;
	char	*str;

	str = ft_strdup("a");
	a = ft_lstnew(str);
	a->next = NULL;
	ft_lstdelone(a, del);
	PASS();
}

SUITE(suite_lstdelone)
{
	RUN_TEST(test_valid);
	RUN_TEST(test_invalid);
	RUN_TEST(test_boundaries);
}

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();
	RUN_SUITE(suite_lstdelone);
	GREATEST_MAIN_END();
}
