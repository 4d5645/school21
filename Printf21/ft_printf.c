/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 08:55:42 by gdara             #+#    #+#             */
/*   Updated: 2021/12/11 08:55:44 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	checkspecifiers(char format, va_list args, int fwe)
{
	if (format == 'c')
		return (write(1, &fwe, 1));
	else if (format == 'd' || format == 'i')
		return (putnbr_int(fwe, "0123456789", 10));
	else if (format == 'u')
		return (putnbr_size_t(fwe, "0123456789", 10, 'u'));
	else if (format == 'x')
		return (putnbr_size_t(fwe, "0123456789abcdef", 16, 'x'));
	else if (format == 'X')
		return (putnbr_size_t(fwe, "0123456789ABCDEF", 16, 'X'));
	else if (format == 'p')
	{
		write(1, "0x", 2);
		return (putnbr_size_t(va_arg(args, size_t), "0123456789abcdef",
				16, 'p') + 2);
	}
	else if (format == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_loop(char *str, int i, int fr, va_list args)
{
	int		fwe;

	fwe = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%' && checknextelem("cpsdiuxX%", str[i + 1]))
		{
			if (checknextelem("dic", str[i + 1]))
				fwe = va_arg (args, int);
			else if (checknextelem("uxX", str[i + 1]))
				fwe = va_arg (args, unsigned int);
			else if (checknextelem("s", str[i + 1]))
				fr += ft_putstr(va_arg (args, char *));
			fr += checkspecifiers(str[i + 1], args, fwe);
			i += 2;
		}
		else
			fr += write(1, &str[i++], 1);
	}
	va_end (args);
	return (fr);
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	int		i;
	int		fr;
	va_list	args;

	i = 0;
	fr = 0;
	str = (char *)s;
	va_start(args, s);
	return (ft_loop(str, i, fr, args));
}
