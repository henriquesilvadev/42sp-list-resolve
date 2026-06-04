/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:32:11 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/04 12:40:58 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* *************************************** */
/* External Libraries                      */
/* *************************************** */

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>

/* *************************************** */
/*  Struct Conversion                      */
/* *************************************** */

# define INIT_FLAG '%'
# define FLAG_MINUS 1
# define FLAG_ZERO 2

typedef struct s_conversion
{
	int		flag;
	size_t	width;
	int		precision;
	bool	precision_set;
	char	specifier;

}	t_conversion;

typedef struct s_print_ops
{
	int	uppercase;
	int	base;

}	t_print_ops;

/* *************************************** */
/* Function list                           */
/* *************************************** */

int				ft_printf(const char *format, ...);
int				handle_conversion(char specifier, va_list *args);
int				ft_putnbr_base_fd(unsigned long long n, char *base, int fd);
int				ft_putnbr_count(int n);
int				print_nbr_base(t_conversion conv, \
								va_list *args, int uppercase, int base);
int				ft_putnbr_unsigned(unsigned int n);
t_conversion	parser_conversion(const char *format, size_t *i);

#endif
