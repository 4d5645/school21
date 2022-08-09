/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:32:56 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 19:35:13 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

/*
** Just a function to check if the stack a is sorted initially
*/

int	a_is_sorted(t_list **stack)
{
	t_list	*current;
	t_list	*check;

	current = *stack;
	if (current == 0)
		return (0);
	while (current != 0)
	{
		check = current->next;
		while (check)
		{
			if (current->content > check->content)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

/*
** Just a function to check that all input arguments are int numbers
*/

static void	check_argvs(int argc, char **argv)
{
	int	i;
	int	j;
	int	content;

	i = 1;
	while (i < argc)
	{
		j = 0;
		content = ft_atoi(argv[i]);
		if (content < -2147483648 || content > 2147483647)
			write_and_close();
		if ((argv[i][j] != '-') && (argv[i][j] > '9' || argv[i][j] < '0'))
			write_and_close();
		j++;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				write_and_close();
			j++;
		}
		i++;
	}
}

/*
** Just a function to check that there are no duplicate arguments
*/

static void	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	j = 1;
	while (j < argc - 1)
	{
		i = j + 1;
		while (i <= argc - 1)
		{
			n = 0;
			while (argv[i][n] != 0 && argv[j][n] != 0)
			{
				if (argv[i][n] != argv[j][n])
					break ;
				n++;
			}
			if (argv[i][n] == 0 && argv[j][n] == 0)
				write_and_close();
			i++;
		}
		j++;
	}
}

/*
** First check the contents of the entered arguments, then push the numbers
** onto the stack a using functions for work with lists
*/

t_list	**initialize_stack(t_list **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	check_argvs(argc, argv);
	check_duplicates(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list *) * (argc - 1));
	if (!stack_a)
	{
		ft_lstclear(stack_a, NULL);
		write_and_close();
	}
	*stack_a = NULL;
	while (i < argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return (&(*stack_a));
}
