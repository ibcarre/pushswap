/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:36:40 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 15:40:06 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_l **stack)
{
	int	tmp;

	if (!(*stack) || !((*stack)->next))
		return ;
	tmp = (*stack)->content;
	(*stack)->content = ((*stack)->next)->content;
	((*stack)->next)->content = tmp;
}

void	rotate_both(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b)
{
	int	i;

	i = 0;
	while (i < idx_a && i < idx_b)
	{
		rot_d(stack_a, stack_b);
		i++;
	}
	while (i < idx_a)
	{
		rot_a(stack_a);
		i++;
	}
	while (i < idx_b)
	{
		rot_b(stack_b);
		i++;
	}
}

void	revrotate_both(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b)
{
	int	i;

	i = 0;
	while (i < get_cost(len_lst(*stack_a), idx_a)
		&& i < get_cost(len_lst(*stack_b), idx_b))
	{
		revrot_d(stack_a, stack_b);
		i++;
	}
	while (i < get_cost(len_lst(*stack_a), idx_a))
	{
		revrot_a(stack_a);
		i++;
	}
	while (i < get_cost(len_lst(*stack_b), idx_b))
	{
		revrot_b(stack_b);
		i++;
	}
}
