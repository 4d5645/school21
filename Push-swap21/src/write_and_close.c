/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_and_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:32:56 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 19:35:13 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

void	write_and_close(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

void	clear_and_close(t_list **stack_a, t_list **stack_b, char flag)
{
	if (flag == 'a')
	{
		ft_lstclear(stack_a, NULL);
		exit(1);
	}
	if (flag == '&')
	{
		ft_lstclear(stack_a, NULL);
		ft_lstclear(stack_b, NULL);
		exit(1);
	}
}
