/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhonorio <hhonorio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 08:39:58 by hhonorio          #+#    #+#             */
/*   Updated: 2026/06/09 08:03:22 by hhonorio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* *************************************** */
/* External Libraries                      */
/* *************************************** */

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

/* *************************************** */
/* Macros                                  */
/* *************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* *************************************** */
/* Function list                           */
/* *************************************** */

char	*get_next_line(int fd);

/* *************************************** */
/* Util list                               */
/* *************************************** */

size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst,	const void *src, size_t n);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);

#endif
