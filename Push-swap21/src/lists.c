/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:23:50 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 19:23:50 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/pushswap.h"

/*
** Just functions that needed to be written in the bonus part of the libft
*/

t_list	*ft_lstnew(int content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->next = NULL;
	elem->content = content;
	return (elem);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst && !(*lst))
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
	return ;
}

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*f;

	if (!new)
		return ;
	if (lst != 0 && *lst != 0)
	{
		f = ft_lstlast(*lst);
		f->next = new;
	}
	else
		*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	if (!lst)
		return ;
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		(void)del;
		cur->next = NULL;
		free(cur);
		cur = NULL;
		cur = next;
	}
	*lst = NULL;
}
