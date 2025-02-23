/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:24:34 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/23 13:16:24 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_l	*ft_lstnew(int	value)
{
	t_l	*new;

	new = malloc(sizeof(t_l));
	if (!new)
		return (NULL);
	new -> content = value;
	new -> next = NULL;
	return (new);
}

t_l	*ft_last(t_l *new)
{
	t_l	*lst;

	if (!new)
		return (NULL);
	lst = new;
	while (lst->next)
		lst = lst -> next;
	return (lst);
}

void	ft_freelst(t_l *head)
{
	if (!head)
		return ;
	if (!(head -> next))
	{
		free(head);
		return ;
	}
	ft_freelst(head -> next);
	free(head);
}

void	ft_lstadd_back(t_l **list, t_l *new)
{
	t_l	*last;

	if (!(*list))
	{
		*list = new;
		return ;
	}
	last = ft_last(*list);
	last->next = new;
}

void	ft_lstadd_front(t_l **list, t_l *new)
{
	if (!(*list))
	{
		*list = new;
		(*list) -> next = NULL;
		return ;
	}
	new -> next = *list;
	*list = new;
}
