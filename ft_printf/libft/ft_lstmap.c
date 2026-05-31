/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 11:04:44 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/28 11:10:40 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*tmp;
	void	*content;

	if (!f || !del || !lst)
		return (NULL);
	result = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
	}
	return (result);
}
