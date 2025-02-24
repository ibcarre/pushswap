/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:12:53 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 15:38:43 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_l **stack)
{
	if ((*stack)->content > ((*stack)->next)->content)
		swap_a(stack);
}

void	sort_three(t_l **stack)
{
	int	min_idx;
	int	max_idx;

	if (len_lst(*stack) == 2)
		return (sort_two(stack));
	min_idx = get_min_idx(*stack);
	max_idx = get_max_idx(*stack);
	if (min_idx == 0 && max_idx == 1)
	{
		revrot_a(stack);
		swap_a(stack);
	}
	else if (min_idx == 2 && max_idx == 1)
		revrot_a(stack);
	else if (max_idx == 0)
		rot_a(stack);
	if ((*stack)->content > ((*stack)->next)->content)
		swap_a(stack);
}

int	get_val(int idx, t_l *stack)
{
	int	i;

	i = 0;
	while (i < idx)
	{
		stack = stack->next;
		i++;
	}
	return (stack->content);
}

int	get_way(int idx_a, t_l *stack_a, int idx_b, t_l *stack_b)
{
	if (idx_a <= len_lst(stack_a) / 2 && idx_b <= len_lst(stack_b) / 2)
	{
		return (1);
	}
	else
		return (0);
}

int	same_half(int idx_a, t_l *stack_a, int idx_b, t_l *stack_b)
{
	if (idx_a <= len_lst(stack_a) / 2 && idx_b <= len_lst(stack_b) / 2)
		return (1);
	if (idx_a > len_lst(stack_a) / 2 && idx_b > len_lst(stack_b) / 2)
		return (1);
	return (0);
}
