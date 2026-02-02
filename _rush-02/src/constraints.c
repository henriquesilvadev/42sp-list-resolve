/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constraints.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 18:23:26 by dieandra          #+#    #+#             */
/*   Updated: 2026/02/01 21:22:48 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"
#include <stdlib.h>

int	ft_is_numeric(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_trim(char *str)
{
	int	i;
	int	j;

	i = 0;
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
	{
		i++;
	}
	j = i;
	while (str[j])
	{
		j++;
	}
	j--;
	while (j >= i && ((str[j] >= 7 && str[j] <= 13) || str[j] == 32))
	{
		str[j] = '\0';
		j--;
	}
	return (&str[i]);
}

int	is_float(char *str)
{
	int	i;
	int	sep;

	i = 0;
	sep = 0;
	if (!str || !*str)
		return (0);
	while (str[i])
	{
		if (str[i] == '.' || str[i] == ',')
		{
			if (sep)
				return (0);
			sep = 1;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (sep);
}

void	ft_process_args(char *num, char *dict_path, t_entry *dict)
{
	int		d_size;
	char	*res;

	d_size = ft_dict_load(dict, dict_path);
	if (d_size < 0)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	if (is_float(num))
	{
		write(1, "Error\n", 6);
		return ;
	}
	res = ft_convert_number(num, dict, d_size);
	if (!res)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	write(1, res, ft_strlen(res));
	write(1, "\n", 1);
	free(res);
}

char	*ft_create_power(int digit)
{
	char	*str;
	int		i;

	if (digit <= 0)
		return (NULL);
	str = malloc(digit + 2);
	if (!str)
		return (NULL);
	str[0] = '1';
	i = 1;
	while (i <= digit)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
