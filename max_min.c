/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:36:24 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 15:42:43 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_min_idx(t_l *stack)
{
	int	idx;
	int	min_idx;
	int	val;

	val = stack->content;
	idx = 0;
	min_idx = 0;
	while (stack)
	{
		if (stack->content < val)
		{
			val = stack->content;
			min_idx = idx;
		}
		idx++;
		stack = stack->next;
	}
	return (min_idx);
}

int	get_min_val(t_l *stack)
{
	int	val;

	val = stack->content;
	while (stack)
	{
		if (stack->content < val)
			val = stack->content;
		stack = stack->next;
	}
	return (val);
}

int	get_max_idx(t_l *stack)
{
	int	idx;
	int	min_idx;
	int	val;

	val = stack->content;
	idx = 0;
	min_idx = 0;
	while (stack)
	{
		if (stack->content > val)
		{
			val = stack->content;
			min_idx = idx;
		}
		idx++;
		stack = stack->next;
	}
	return (min_idx);
}

int	get_max_val(t_l *stack)
{
	int	val;

	val = stack->content;
	while (stack)
	{
		if (stack->content > val)
			val = stack->content;
		stack = stack->next;
	}
	return (val);
}

t_l	*skip_to_min(t_l *stack_a, int *i)
{
	while (stack_a -> content != get_min_val(stack_a))
	{
		(*i)++;
		stack_a = stack_a -> next;
	}
	return (stack_a);
}
