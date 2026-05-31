/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 11:54:15 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/31 12:11:27 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
	int		n;
	void	*ptr;

	n = 42;
	ptr = &n;

	// %s
	ft_printf("ft: %s\n", "hello");
	printf("og: %s\n", "hello");
	ft_printf("ft: %s\n", NULL);
	printf("og: %s\n", (char *)NULL);

	// %c
	ft_printf("ft: %c\n", 'A');
	printf("og: %c\n", 'A');

	// %d e %i
	ft_printf("ft: %d\n", 42);
	printf("og: %d\n", 42);
	ft_printf("ft: %d\n", -42);
	printf("og: %d\n", -42);
	ft_printf("ft: %d\n", -2147483648);
	printf("og: %d\n", (int)-2147483648);

	// %u
	ft_printf("ft: %u\n", -1);
	printf("og: %u\n", -1);
	ft_printf("ft: %u\n", 0);
	printf("og: %u\n", 0);

	// %x e %X
	ft_printf("ft: %x\n", 255);
	printf("og: %x\n", 255);
	ft_printf("ft: %X\n", 255);
	printf("og: %X\n", 255);

	// %p
	ft_printf("ft: %p\n", ptr);
	printf("og: %p\n", ptr);
	ft_printf("ft: %p\n", NULL);
	printf("og: %p\n", NULL);

	// %%
	ft_printf("ft: 100%%\n");
	printf("og: 100%%\n");

	return (0);
}
