/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+          +:+    */
/*   By: hhonorio <hhonorio@student.42sp.org.br>     +#+  +:+        +#+      */
/*                                                 +#+#+#+#+#+     +#+        */
/*   Created: 2026/01/11 00:00:00 by hhonorio            #+#     #+#          */
/*   Updated: 2026/01/16 14:51:30 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	alphabet;

	alphabet = 'a';
	while (alphabet <= 'z')
	{
		ft_putchar(alphabet);
		alphabet++;
	}
}

/**
int main(void)
{
	ft_print_alphabet();
	return (0);
}
**/
