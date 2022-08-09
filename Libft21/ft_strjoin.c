/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:27:38 by gdara             #+#    #+#             */
/*   Updated: 2021/11/08 18:53:12 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	char			*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc(sizeof(char const)
			*(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	while (j < ft_strlen(s1))
	{
		ptr[j] = s1[j];
		j++;
	}
	while (i < ft_strlen(s2))
	{
		ptr[j] = s2[i];
		i++;
		j++;
	}
	ptr[j++] = '\0';
	return (ptr);
}
