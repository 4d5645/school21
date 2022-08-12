/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:55:56 by gdara             #+#    #+#             */
/*   Updated: 2021/12/11 08:55:58 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
int		ft_loop(char *str, int i, int fr, va_list args);
size_t	putnbr_size_t(size_t nb, char *base, int base_len, char format);
size_t	putnbr_int(int nb, char *base, int base_len);
int		ft_putstr(char *s);
size_t	checknextelem(char *s, int c);
int		checkspecifiers(char format, va_list args, int fwe);
int		ft_printf(const char *s, ...);
#endif
