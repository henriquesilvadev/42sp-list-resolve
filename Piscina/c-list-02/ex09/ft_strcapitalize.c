/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 09:42:31 by hhonorio          #+#    #+#             */
/*   Updated: 2026/01/19 14:32:44 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	digit_valid;

	i = 0;
	while (str[i])
	{
		digit_valid = !((str[i - 1] >= 'a' && str[i - 1] <= 'z') || \
						(str[i - 1] >= 'A' && str[i - 1] <= 'Z') || \
						(str[i - 1] >= '0' && str[i - 1] <= '9'));
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (i == 0 || digit_valid)
					str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (!(i == 0 || digit_valid))
					str[i] += 32;
		}
		i++;
	}
	return (str);
}
