/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:36:40 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 13:30:27 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push(t_l **stack, t_l **stack_d)
{
	t_l	*tmp;

	tmp = (*stack_d)->next;
	ft_lstadd_front(stack, *stack_d);
	*stack_d = tmp;
}

void	ft_rot(t_l **stack)
{
	t_l	*tmp;

	if (!((*stack)->next))
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack, tmp);
}

void	ft_rot_d(t_l **stack, t_l **stack_d)
{
	ft_rot(stack);
	ft_rot(stack_d);
}

void	ft_revrot(t_l **stack)
{
	t_l	*tmp;
	t_l	*lst;

	if (!((*stack)->next))
		return ;
	tmp = *stack;
	while ((tmp->next)->next)
		tmp = tmp->next;
	lst = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack, lst);
}

void	ft_revrot_d(t_l **stack, t_l **stack_d)
{
	ft_revrot(stack);
	ft_revrot(stack_d);
}
