/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 09:10:06 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/13 12:07:59 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_by(int size, char *value[])
{
	int			i;
	int			j;
	char	*temp;

	i = 1;
	while (i < size - i)
	{
		j = 1;
		while (j < size - 1)
		{
			if (ft_strcmp(value[j], value[j - 1]) > 0)
			{
				temp = value[j];
				value[j] = value[j + 1];
				value[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_params(int size, char *value[])
{
	int	i;

	ft_sort_by(size, value);

	i = 1;
	while (i < size)
	{
		ft_putstr(value[i++]);
		ft_putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	ft_sort_params(argc, argv);
	return (0);
}
