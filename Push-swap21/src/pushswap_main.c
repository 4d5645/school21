/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:32:56 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 19:35:13 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

/*
** Do bubble sort for array with elements as in stack a,
** write down for each element of the stack its index 
** in the sorted array (its final place).
** Do sorting depending on the number of input arguments.
*/

static void	sort(t_list **stack_a, t_list **stack_b, int *indicies, int count)
{
	bubble_sort(indicies, count);
	initialize_indicies(stack_a, indicies, count);
	if (count == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			run_swap(stack_a, 0, 'a');
	}
	else if (count == 3)
		sort_three(stack_a);
	else if (count <= 5)
		sort_fiveorless(stack_a, stack_b, count);
	else
		sort_a_lot(stack_a, stack_b, count);
}

/*
** Check if entered arguments were correct, create and initialize stack a,
** create array with same elements as in stack a, create stack b, 
** call sort function
*/

int	main(int argc, char **argv)
{
	int		*indicies;
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = NULL;
	if (argc < 2)
		exit(1);
	stack_a = initialize_stack(stack_a, argc, argv);
	indicies = ft_fill_array(stack_a, argc - 1);
	if (!indicies)
		exit(1);
	if (argc < 3)
		clear_and_close(stack_a, NULL, 'a');
	if (a_is_sorted(stack_a) == 1)
		clear_and_close(stack_a, NULL, 'a');
	stack_b = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!stack_b)
		clear_and_close(stack_a, stack_b, '&');
	*stack_b = NULL;
	sort(stack_a, stack_b, indicies, argc - 1);
	free(stack_b);
	free(indicies);
	return (0);
}
