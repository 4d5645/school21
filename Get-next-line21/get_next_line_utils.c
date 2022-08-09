/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:58:00 by gdara             #+#    #+#             */
/*   Updated: 2021/11/15 18:05:58 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str != (char)c)
		return (0);
	else if (*str == '\0')
		return (0);
	else
		return ((char *)str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc(sizeof(char const)
			*(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	while (s1[j] != 0)
	{
		ptr[j] = s1[j];
		j++;
	}
	while (s2[i] != 0)
	{
		ptr[j] = s2[i];
		i++;
		j++;
	}
	ptr[j++] = '\0';
	return (ptr);
}

void	*ft_memcpy(void *restrict dest, const void *restrict source,
		size_t count)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr2;

	ptr = (unsigned char *)dest;
	ptr2 = (unsigned char *)source;
	i = 0;
	if (!dest && !source)
		return (0);
	while (count != 0)
	{
		ptr[i] = ptr2[i];
		i++;
		count--;
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(s1) + 1;
	ptr = (char *)malloc(len * sizeof(const char));
	if (!ptr)
		return (0);
	ft_memcpy(ptr, s1, len);
	return (ptr);
}
