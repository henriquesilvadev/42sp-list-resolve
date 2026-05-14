/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:09:24 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/13 12:32:02 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int	i;
	char	*copy;

	copy = malloc(sizeof(char) * (ft_strlen(src) + 1));

	if (!copy)
		return (0);
	i = 0;
	while (src[i])
		copy[i++] = src[i++];
	copy[i] = '\0';

	return (copy);
}
