/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:32:11 by hhonorio          #+#    #+#             */
/*   Updated: 2026/05/31 08:51:26 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

/* *************************************** */
/* External Libraries                      */
/* *************************************** */

# include "libft/libft.h"
# include <stdarg.h>
# include <complex.h>

/* *************************************** */
/* Function list                           */
/* *************************************** */

int	ft_printf(const char *format, ...);
int	handle_conversion(char c, va_list *args);
int	ft_putnbr_base_fd(unsigned long long b, char *base, int fd);

#endif
