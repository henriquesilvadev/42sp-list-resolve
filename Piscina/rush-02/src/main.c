/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dieandra <dieandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 19:39:40 by asoeiro-          #+#    #+#             */
/*   Updated: 2026/02/01 20:57:42 by dieandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <library.h>

#define MAX_ENTRIES 100
#define FILE_PATH "./numbers.dict"

char	*ft_convert_number(char *nbr, t_entry *dict, int size);

int	main(int argc, char **argv)
{
	t_entry	dict[MAX_ENTRIES];

	if (argc == 2)
		ft_process_args(argv[1], FILE_PATH, dict);
	else if (argc == 3)
		ft_process_args(argv[2], argv[1], dict);
	else
		write(1, "Error\n", 6);
	return (0);
}
