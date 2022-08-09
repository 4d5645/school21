/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 23:10:04 by gdara             #+#    #+#             */
/*   Updated: 2021/10/24 19:06:34 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)arr;
	while (n--)
	{
		if (*ptr != (unsigned char) c)
			ptr++;
		else
			return (ptr);
	}
	return (0);
}
