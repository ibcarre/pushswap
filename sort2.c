/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:12:53 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 15:39:56 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	change_stacks(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b)
{
	int	way;

	way = get_way(idx_a, *stack_a, idx_b, *stack_b);
	if (way == 1)
		rotate_both(idx_a, stack_a, idx_b, stack_b);
	else
		revrotate_both(idx_a, stack_a, idx_b, stack_b);
}

int	get_corr_a(int val, t_l *stack_a)
{
	int	i;

	i = 0;
	if (val < get_min_val(stack_a))
		return (get_min_idx(stack_a));
	if (val > get_max_val(stack_a))
		return (get_max_idx(stack_a) + 1);
	if (val < stack_a->content && val > get_min_val(stack_a))
	{
		stack_a = skip_to_min(stack_a, &i);
		while (stack_a)
		{
			if (val < stack_a->content)
				return (i);
			i++;
			stack_a = stack_a->next;
		}
	}
	while (stack_a && val > stack_a->content)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (i);
}

void	sort_b(t_l **stack_a, t_l **stack_b)
{
	int	cheap_idx;
	int	corr_b;

	while (len_lst(*stack_a) > 3)
	{
		cheap_idx = get_cheapest_b(*stack_a, *stack_b);
		corr_b = get_corr_b(get_val(cheap_idx, *stack_a), *stack_b);
		if (same_half(cheap_idx, *stack_a, corr_b, *stack_b))
			change_stacks(cheap_idx, stack_a, corr_b, stack_b);
		else
			change_one(cheap_idx, stack_a, corr_b, stack_b);
		push_b(stack_b, stack_a);
	}
	return ;
}

void	sort_a(t_l **stack_a, t_l **stack_b)
{
	int	cheap_idx;
	int	i;

	while (*stack_b)
	{
		i = 0;
		cheap_idx = get_corr_a((*stack_b)->content, *stack_a);
		if (cheap_idx <= len_lst(*stack_a) / 2)
		{
			while (i < cheap_idx)
			{
				rot_a(stack_a);
				i++;
			}
		}
		else
		{
			while (i < len_lst(*stack_a) - cheap_idx)
			{
				revrot_a(stack_a);
				i++;
			}
		}
		push_a(stack_a, stack_b);
	}
}

void	sort(t_l **stack_a, t_l **stack_b)
{
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	sort_b(stack_a, stack_b);
	sort_three(stack_a);
	sort_a(stack_a, stack_b);
	if (get_min_idx(*stack_a) < len_lst(*stack_a) / 2)
	{
		while ((*stack_a)->content != get_min_val(*stack_a))
			rot_a(stack_a);
	}
	else
	{
		while ((*stack_a)->content != get_min_val(*stack_a))
			revrot_a(stack_a);
	}
	ft_freelst(*stack_a);
	ft_freelst(*stack_b);
}
