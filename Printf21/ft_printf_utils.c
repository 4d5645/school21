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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	checknextelem(char *s, int c)
{
	if (!s)
		return (write(1, "(null)", 6));
	while (*s != 0)
	{
		if (*s == (char)c)
			return (1);
		s++;
	}
	return (0);
}

size_t	putnbr_size_t(size_t nb, char *base, int base_len, char format)
{
	int		len;
	int		i;
	char	str[30];

	i = 0;
	len = 0;
	if (checknextelem("uxX", format))
		nb = (unsigned int) nb;
	if (nb == 0)
		return (write(1, base, 1));
	while (nb != 0)
	{
		str[i++] = base[nb % base_len];
		nb /= base_len;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}

size_t	putnbr_int(int nb, char *base, int base_len)
{
	int		len;
	int		i;
	char	str[30];

	i = 0;
	len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		len++;
	}
	if (nb == 0)
		return (write(1, base, 1));
	while (nb != 0)
	{
		str[i++] = base[nb % base_len];
		nb /= base_len;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}

int	ft_putstr(char *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	if (s != 0)
	{
		while (i < len)
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (len);
}
