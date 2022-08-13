/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:08:36 by gdara             #+#    #+#             */
/*   Updated: 2021/10/25 20:42:44 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	i = 0;
	if (!dest && !source)
		return (0);
	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)source;
	if (dest > source)
	{
		while (n--)
			ptr[n] = ptr2[n];
	}
	else
	{
		while (i < n)
		{
			ptr[i] = ptr2[i];
			i++;
		}
	}
	return (dest);
}
