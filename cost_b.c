/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:05:58 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/23 11:20:48 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_corr_b(int val, t_l *stack_b)
{
	int	i;

	i = 0;
	if (val > stack_b->content && val < get_max_val(stack_b))
	{
		while (stack_b->content != get_max_val(stack_b))
		{
			i++;
			stack_b = stack_b->next;
		}
		while (stack_b)
		{
			if (val > stack_b->content)
				return (i);
			i++;
			stack_b = stack_b->next;
		}
	}
	while (stack_b && val < stack_b->content)
	{
		i++;
		stack_b = stack_b->next;
	}
	return (i);
}

int	get_cost(int len, int idx)
{
	if (idx <= len / 2)
		return (idx);
	return (len - idx);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
