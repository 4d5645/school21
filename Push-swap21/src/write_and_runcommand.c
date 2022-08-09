/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_and_runcommand.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:21:45 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 19:21:45 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

void	run_swap(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	else if (flag == 'b')
	{
		swap(stack_b);
		write(1, "sb\n", 3);
	}
	else if (flag == '&')
	{
		swap(stack_a);
		swap(stack_b);
		write(1, "ss\n", 3);
	}
	else
		return ;
}

void	run_push(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		push(stack_a, stack_b);
		write(1, "pa\n", 3);
	}
	else if (flag == 'b')
	{
		push(stack_b, stack_a);
		write(1, "pb\n", 3);
	}
	else
		return ;
}

void	run_rotate(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if (flag == 'b')
	{
		rotate(stack_b);
		write(1, "rb\n", 3);
	}
	else if (flag == '&')
	{
		rotate(stack_a);
		rotate(stack_b);
		write(1, "rr\n", 3);
	}
	else
		return ;
}

void	run_reverse_rotate(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		reverse_rotate(stack_a);
		write(1, "rra\n", 4);
	}
	else if (flag == 'b')
	{
		reverse_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (flag == '&')
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
	else
		return ;
}
