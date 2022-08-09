/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:44:41 by gdara             #+#    #+#             */
/*   Updated: 2021/11/22 20:44:45 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

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

static void	free_remainder(char **remainder)
{
	free(*remainder);
	*remainder = 0;
}

static char	*return_line(int bwr, char **remainder, char **line)
{
	char	*pointer_n;
	char	*tmp;

	if (bwr < 0 || (bwr == 0 && *remainder == 0))
		return (0);
	pointer_n = ft_strchr(*remainder, '\n');
	if (pointer_n != 0)
	{
		*line = ft_substr(*remainder, 0,
				ft_strlen(*remainder) - ft_strlen(pointer_n) + 1);
		tmp = ft_strdup(++pointer_n);
		free(*remainder);
		*remainder = tmp;
		if ((*remainder)[0] == '\0')
			free_remainder(remainder);
	}
	else
	{
		*line = ft_strdup(*remainder);
		free_remainder(remainder);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	int			bwr;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483647)
		return (0);
	bwr = read(fd, buff, BUFFER_SIZE);
	while (bwr > 0)
	{
		buff[bwr] = '\0';
		if (remainder != 0)
		{
			tmp = ft_strjoin(remainder, buff);
			free(remainder);
			remainder = tmp;
		}
		else
			remainder = ft_strdup(buff);
		if (ft_strchr(remainder, '\n'))
			break ;
		bwr = read(fd, buff, BUFFER_SIZE);
	}
	return (return_line(bwr, &remainder, &line));
}
