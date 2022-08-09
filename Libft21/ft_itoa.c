/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:27:42 by gdara             #+#    #+#             */
/*   Updated: 2021/11/09 10:45:57 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	take_size(int n)
{
	if (n > 0)
		return (0);
	else
		return (1);
}

static int	take_sign(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

static void	check(size_t size, char *str)
{
	if (size == 0 && str[1] == '\0')
		str[size] = '0';
	else if (size == 0 && str[1] != '\0')
		str[size] = '-';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int		nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = take_size(n);
	nb = take_sign(n);
	while (n)
	{
		n /= 10;
		size++;
	}
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!(str))
		return (0);
	str[size--] = '\0';
	while (nb > 0)
	{
		str[size--] = nb % 10 + '0';
		nb /= 10;
	}
	check(size, str);
	return (str);
}
