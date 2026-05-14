/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoeiro- <asoeiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 12:19:46 by hhonorio          #+#    #+#             */
/*   Updated: 2026/02/01 21:48:09 by asoeiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <library.h>
#include <stdlib.h>
#include <dict.h>

char	*ft_convert_small(char *nbr, t_entry *dict, int size)
{
	char	*word;
	char	*t;
	char	tmp[3];

	word = ft_dict_get(dict, size, nbr);
	if (word)
		return (ft_strdup(word));
	if (ft_strlen(nbr) != 2)
		return (NULL);
	tmp[0] = nbr[0];
	tmp[1] = '0';
	tmp[2] = '\0';
	t = ft_dict_get(dict, size, tmp);
	if (nbr[1] == '0' || !t)
	{
		if (t)
			return (ft_strdup(t));
		return (NULL);
	}
	tmp[0] = nbr[1];
	tmp[1] = '\0';
	word = ft_dict_get(dict, size, tmp);
	return (ft_join(t, word));
}

int	ft_split_by_power(char *nbr, char *left, char *right, char **power)
{
	int	len;
	int	p_len;
	int	split;

	len = ft_strlen(nbr);
	if (len <= 2)
		return (0);
	p_len = ((len - 1) / 3) * 3;
	if (p_len == 0)
		p_len = 2;
	split = len - p_len;
	if (split <= 0)
		return (-1);
	*power = ft_create_power(p_len);
	if (!*power)
		return (-1);
	ft_strncpy(left, nbr, split);
	left[split] = '\0';
	ft_strcpy(right, nbr + split);
	return (1);
}

static char	*ft_append_right(char *res, char *right, t_entry *dict, int size)
{
	char	*tmp;
	char	*new_res;

	if (ft_is_zero_str(right))
		return (res);
	tmp = ft_convert_number(right, dict, size);
	if (!tmp)
		return (res);
	if (!res)
		return (tmp);
	new_res = ft_join(res, tmp);
	free(res);
	free(tmp);
	return (new_res);
}

static char	*ft_get_compound(char *left, char *power, t_entry *dict, int size)
{
	char	*w;
	char	*tmp;
	char	*res;
	char	*p_word;

	p_word = ft_dict_get(dict, size, power);
	tmp = ft_convert_number(left, dict, size);
	if (!p_word || !tmp)
	{
		free(tmp);
		return (NULL);
	}
	w = ft_strdup(p_word);
	res = ft_join(tmp, w);
	free(tmp);
	free(w);
	return (res);
}

char	*ft_convert_number(char *nbr, t_entry *dict, int size)
{
	char	left[64];
	char	right[64];
	char	*pwr;
	char	*res;
	char	*w;

	if (ft_is_zero_str(nbr))
	{
		w = ft_dict_get(dict, size, "0");
		if (w)
			return (ft_strdup(w));
		return (NULL);
	}
	if (ft_strlen(nbr) <= 2)
		return (ft_convert_small(nbr, dict, size));
	if (ft_split_by_power(nbr, left, right, &pwr) <= 0)
		return (NULL);
	res = ft_get_compound(left, pwr, dict, size);
	free(pwr);
	if (!res)
		return (NULL);
	return (ft_append_right(res, right, dict, size));
}
