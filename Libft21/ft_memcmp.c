/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:14:47 by gdara             #+#    #+#             */
/*   Updated: 2021/10/25 20:47:21 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	i = 1;
	if (n == 0)
		return (0);
	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	while (*ptr1 == *ptr2 && i < n)
	{
		ptr1++;
		ptr2++;
		i++;
	}
	return ((int)(*ptr1 - *ptr2));
}
