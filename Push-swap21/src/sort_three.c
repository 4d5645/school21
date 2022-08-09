/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:05:13 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 20:05:13 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

/*
** Declare some threshold value (I picked up 20). Elements whose indices 
** are greater than it are left on stack a and we scroll 
** through stack a. Elements less than it 
** are pushed onto the stack b, we increase the threshold by 1. 
** This is a small presort so that the algorithm can cope faster
*/

static void	presort(t_list **stack_a, t_list **stack_b, int count)
{
	int	threshold;

	if (count <= 100)
		threshold = 8;
	else
		threshold = 20;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index > threshold)
			run_rotate(stack_a, stack_b, 'a');
		else
		{
			run_push(stack_a, stack_b, 'b');
			threshold++;
		}
	}
}

/*
** Just count the number of steps to the element with the highest index
*/

static int	cost_of_push(t_list *stack_b, int index)
{
	int	i;

	i = 0;
	if (stack_b)
	{
		while (stack_b->index != index)
		{
			stack_b = stack_b->next;
			i++;
		}
	}
	return (i);
}

/*
** Look for the median index in the stack b, calculate the cost of the 
** push operation in the stack a for the element with the maximum index. 
** If the cost is 0, then push. If it is greater than the median value, 
** then do reverse rotate, otherwise do rotate
*/

void	sort_a_lot(t_list **stack_a, t_list **stack_b, int count)
{
	int	median;
	int	cost;
	int	max_index;

	presort(stack_a, stack_b, count);
	max_index = count - 1;
	while (*stack_b)
	{
		cost = cost_of_push(*stack_b, max_index);
		median = max_index / 2;
		if (!cost)
		{
			run_push(stack_a, stack_b, 'a');
			max_index--;
		}
		else if (cost > median)
			run_reverse_rotate(0, stack_b, 'b');
		else
			run_rotate(0, stack_b, 'b');
	}
}

/*
** trird element = second->next
**
** If 3 > 1 and 2 < 1 swap the first 2 elements at the top of stack a
**
** If 3 < 2 and 1 > 2 swap the first 2 elements at the top of stack a
** and the last element becomes the first one in stack a
**
** If 3 < 1 and 2 < 3 the first element becomes the last one in stack a
**
** If 2 > 3 and 1 < 3 swap the first 2 elements at the top of stack a
** and the first element becomes the last one in stack a
**
** If 1 < 2 and 3 < 1 the last element becomes the first one in stack a
*/

void	sort_three(t_list **stack)
{
	t_list	*second;

	second = (*stack)->next;
	if (second->next->content > (*stack)->content
		&& second->content < (*stack)->content)
		run_swap(stack, 0, 'a');
	else if (second->next->content < second->content
		&& (*stack)->content > second->content)
	{
		run_swap(stack, 0, 'a');
		run_reverse_rotate(stack, 0, 'a');
	}
	else if (second->next->content < (*stack)->content
		&& second->content < second->next->content)
		run_rotate(stack, 0, 'a');
	else if (second->content > second->next->content
		&& (*stack)->content < second->next->content)
	{
		run_swap (stack, 0, 'a');
		run_rotate (stack, 0, 'a');
	}
	else if ((*stack)->content < second->content
		&& second->next->content < (*stack)->content)
		run_reverse_rotate (stack, 0, 'a');
}

/*
** Find the smallest and largest elements in stack a using 
** their indexes equal to the indexes in the sorted array. Push 
** these elements on the stack b. Sorting the 3 remaining
** elements on the stack a. Return elements from the stack b
*/

void	sort_fiveorless(t_list **stack_a, t_list **stack_b, int count)
{
	int	last_index;

	last_index = count - 1;
	while (count > 3)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == last_index)
		{
			run_push(stack_a, stack_b, 'b');
			count--;
		}
		else
			run_rotate(stack_a, 0, 'a');
	}
	sort_three (stack_a);
	while (*stack_b)
	{
		if ((*stack_b)->index == 0)
			run_push(stack_a, stack_b, 'a');
		else if ((*stack_b)->index == last_index)
		{
			run_push(stack_a, stack_b, 'a');
			run_rotate(stack_a, 0, 'a');
		}
	}
}
