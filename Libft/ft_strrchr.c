/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 15:32:30 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/18 10:40:03 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	unsigned char	uc;

	uc = (unsigned char) c;
	res = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == uc)
			res = (char *) &s[i];
		i++;
	}
	if (s[i] == uc)
		res = (char *) &s[i];
	return (res);
}

int	main(void)
{
	char	*result;
	char	*str;

	str = "MESTRE";
	result = ft_strrchr(str, 'E');
	if (result)
		printf("Encontrado: %s\n", result);
	else
		printf("Não encontrado\n");
	return (0);
}
