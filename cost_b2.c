/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:15:46 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/23 12:34:05 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_costs(int len_a, int idx_a, int len_b, int idx_b)
{
	int	mini;
	int	maxi;

	maxi = max(get_cost(len_a, idx_a), get_cost(len_b, idx_b));
	mini = min(get_cost(len_a, idx_a), get_cost(len_b, idx_b));
	if (idx_a <= len_a / 2 && idx_b <= len_b / 2)
		return (get_cost(len_a, idx_a) + get_cost(len_b, idx_b) - mini);
	if (idx_a > len_a / 2 && idx_b > len_b / 2)
		return (get_cost(len_a, idx_a) + get_cost(len_b, idx_b) - mini);
	if (maxi < get_cost(len_a, idx_a) + get_cost(len_b, idx_b))
		return (maxi);
	return (get_cost(len_a, idx_a) + get_cost(len_b, idx_b));
}

int	len_lst(t_l *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

// cheapest 0 : val stack_a, 1 cost, 2 idx a;

void	set_cheap(int cheap[3], int cur[3])
{
	if (cheap[0] < cur[0])
	{
		cheap[0] = cur[0];
		cheap[1] = cur[1];
		cheap[2] = cur[2];
	}
}

int	get_cheapest_b(t_l *stack_a, t_l *stack_b)
{
	int	cheap[3];
	int	cur[3];
	int	len_a;

	cheap[0] = stack_a->content;
	cheap[2] = 0;
	cur[2] = 0;
	len_a = len_lst(stack_a);
	cheap[1] = get_cost(len_lst(stack_b), get_corr_b(cheap[0], stack_b));
	while (stack_a)
	{
		cur[0] = stack_a->content;
		cur[1] = get_costs(len_a, cur[2], len_lst(stack_b), get_corr_b(cur[0],
					stack_b));
		if (cheap[1] >= cur[1])
			set_cheap(cheap, cur);
		stack_a = stack_a->next;
		cur[2]++;
	}
	return (cheap[2]);
}
