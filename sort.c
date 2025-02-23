/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:12:53 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/23 13:13:35 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_l **stack)
{
	if ((*stack) -> content > ((*stack)-> next) -> content)
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
		stack = stack -> next;
		i++;
	}
	return (stack -> content);
}

int	same_half(int idx_a, t_l *stack_a, int idx_b, t_l *stack_b, int *way)
{
	if (idx_a <= len_lst(stack_a)/2 && idx_b <= len_lst(stack_b)/2)
	{
		*way = 1;
		return (1);
	}
	if (idx_a > len_lst(stack_a)/2 && idx_b > len_lst(stack_b)/2)
	{
		*way= 0;
		return (1);
	}
	return (0);
}

void	change_stacks(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b, int way)
{
	int	i;

	i = 0;
	if (way == 1) //rotate
	{
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
	else //revrot
	{
		while (i < get_cost(len_lst(*stack_a), idx_a) && i < get_cost(len_lst(*stack_b) ,idx_b))
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
}
void	change_one(int idx_a, t_l **stack_a, int idx_b, t_l **stack_b)
{
	int	idx;

	idx = 0;
	if (idx_a < len_lst(*stack_a)/2)
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
	idx = 0;
	if (idx_b < len_lst(*stack_b)/2)
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

int	get_corr_a(int val, t_l *stack_a)
{
	int	i;

	i = 0;
	if (val < get_min_val(stack_a))
		return (get_min_idx(stack_a));
    if (val > get_max_val(stack_a))
		return (get_max_idx(stack_a) + 1);
	if (val < stack_a -> content && val > get_min_val(stack_a))
	{
		while (stack_a -> content != get_min_val(stack_a)) //stack_b -> content != get_max_val(stack_b)  i <= get_max_idx(stack_b)
		{
			i++;
			stack_a = stack_a -> next;
			//printf("VAL %i\nIIIIII %i\nstack B CONTENT %i\n",val, i, stack_b->content);
		}
		while (stack_a)
		{
			if (val < stack_a -> content)
				return (i);
			i++;
			stack_a = stack_a -> next;
		}
	}
	while (stack_a && val > stack_a -> content)
	{
		i++;
		stack_a = stack_a -> next;
	}
	return (i);
}

void	sort(t_l **stack_a, t_l **stack_b)
{
	int	cheap_idx;
	int	way;
	int	corr_b;
	int	i;

	i = 0;
	push_b(stack_b, stack_a);
	push_b(stack_b, stack_a);
	while (len_lst(*stack_a) > 3)
	{
		cheap_idx = get_cheapest_b(*stack_a, *stack_b);
		//printf("CHEAP IDX%i\n", cheap_idx);
		corr_b = get_corr_b(get_val(cheap_idx, *stack_a), *stack_b);
		//printf("CORR B %i\n", corr_b);
		if (same_half(cheap_idx, *stack_a, corr_b, *stack_b, &way))
			change_stacks(cheap_idx, stack_a, corr_b, stack_b, way);
		else
			change_one(cheap_idx, stack_a, corr_b, stack_b);
		push_b(stack_b, stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		cheap_idx = get_corr_a((*stack_b)-> content, *stack_a);
		if (cheap_idx <= len_lst(*stack_a)/2)
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
		i = 0;
		push_a(stack_a, stack_b);
	}
	if (get_min_idx(*stack_a) < len_lst(*stack_a)/2)
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
