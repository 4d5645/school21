/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:34:16 by gdara             #+#    #+#             */
/*   Updated: 2021/11/08 18:56:01 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{	
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_end(char const *s1, char const *set, size_t start)
{
	size_t	i;

	i = 0;
	i = ft_strlen(s1);
	while (i > start && ft_isinset(s1[i - 1], set))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	j;
	char	*ptr;

	start = 0;
	if (!s1)
		return (0);
	while (s1[start] && ft_isinset(s1[start], set))
		start++;
	end = find_end(s1, set, start);
	ptr = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!ptr)
		return (0);
	j = 0;
	while (start < end)
		ptr[j++] = s1[start++];
	ptr[j] = '\0';
	return (ptr);
}
