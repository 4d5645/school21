/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:53:56 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 19:53:56 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

/*
** Fill array with values from stack a
*/

int	*ft_fill_array(t_list **stack, int n)
{
	int		i;
	t_list	*one;
	int		*array;

	i = 0;
	one = *stack;
	array = (int *)malloc(sizeof(int) * n);
	if (!array)
		return (0);
	while (n--)
	{
		array[i++] = one->content;
		one = one->next;
	}
	return (array);
}

/*
** Swap 2 elements
*/

static void	swap_bubble(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

/*
** Classic bubble sort in array
*/

void	bubble_sort(int *array, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (array[j] > array[j + 1])
				swap_bubble(&array[j], &array[j + 1]);
			j++;
		}
		i++;
	}
}

/*
** Function to write down for each element of the stack its index 
** in the sorted array (its final place).
*/

void	initialize_indicies(t_list **stack, int *array, int count)
{
	int		i;
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < count)
		{
			if (tmp->content == array[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}
