/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:47:25 by gdara             #+#    #+#             */
/*   Updated: 2021/11/08 20:23:17 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	flag;

	i = 0;
	flag = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

static char	*memory_error(char **array, int size)
{
	while (size != 0)
	{
		free((void **)&array[size]);
		size--;
	}
	free((void **)&array);
	return (0);
}

static char	*word_in(char const *s, int start, int end)
{
	int		i;
	int		size;
	char	*word;

	i = 0;
	size = end - start;
	word = malloc((size + 1) * sizeof(char));
	if (!word)
		return (0);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	body_of_func(char const *s, char c, char **array)
{
	size_t		i;
	int			j;
	int			k;

	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && k < 0)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			array[j] = word_in(s, k, i);
			if (!array[j])
			{
				memory_error(array, k);
			}
			j++;
			k = -1;
		}
		i++;
	}
	array[j] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!array)
		return (0);
	body_of_func(s, c, array);
	return (array);
}
