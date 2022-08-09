/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:22:27 by gdara             #+#    #+#             */
/*   Updated: 2021/11/10 20:25:35 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	else
	{
		if (start >= ft_strlen(s))
		{
			str = (char *)malloc(sizeof(char));
			if (!str)
				return (0);
			*str = '\0';
			return (str);
		}
		if (start + len > ft_strlen(s))
			len = ft_strlen(s) - start;
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (0);
		i = 0;
		ft_strlcpy(str, s + start, len + 1);
		return (str);
	}
}
