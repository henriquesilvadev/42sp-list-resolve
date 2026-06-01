/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:32:11 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/01 11:11:00 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/* *************************************** */
/* External Libraries                      */
/* *************************************** */

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

/* *************************************** */
/*  Struct Conversion                      */
/* *************************************** */

# define INIT_FLAG '%'
# define FLAG_MINUS 1
# define FLAG_ZERO 2

typedef struct s_conversion
{
	char	flag;
	int		width;
	int		precision;
	bool	precision_set;
	char	specifier;

}	t_conversion;

/* *************************************** */
/* Function list                           */
/* *************************************** */

int				ft_printf(const char *format, ...);
int				handle_conversion(t_conversion conv, va_list *args);
int				ft_putnbr_base_fd(unsigned long long n, char *base, int fd);
int				ft_putnbr_count(int n);
int				ft_putnbr_unsigned(unsigned int n);
t_conversion	parser_conversion(const char *format, size_t *i);

#endif
