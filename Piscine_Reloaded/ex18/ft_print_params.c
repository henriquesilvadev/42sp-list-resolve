/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 08:59:28 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/13 09:15:24 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_print_params(int size, char *value[])
{
	int i;
	int j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (value[i][j] != '\0')
		{
			ft_putchar(value[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int main(int argc, char *argv[])
{
	ft_print_params(argc, argv);
	return (0);
}