/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:25:46 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 15:42:09 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	change_a(int idx_a, t_l **stack_a)
{
	int	idx;

	idx = 0;
	if (idx_a < len_lst(*stack_a) / 2)
	{
		while (idx < idx_a)
		{
			rot_a(stack_a);
			idx++;
		}
	}
	else
	{
		while (idx < get_cost(len_lst(*stack_a), idx_a))
		{
			revrot_a(stack_a);
			idx++;
		}
	}
}

void	change_b(int idx_b, t_l **stack_b)
{
	int	idx;

	idx = 0;
	if (idx_b < len_lst(*stack_b) / 2)
	{
		while (idx < idx_b)
		{
			rot_b(stack_b);
			idx++;
		}
	}
	else
	{
		while (idx < get_cost(len_lst(*stack_b), idx_b))
		{
			revrot_b(stack_b);
			idx++;
		}
	}
}

void	change_one(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b)
{
	change_a(idx_a, stack_a);
	change_b(idx_b, stack_b);
}
