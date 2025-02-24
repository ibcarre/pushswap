/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:58:12 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 13:28:23 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_l **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_l **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	push_a(t_l **stack_a, t_l **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	push_b(t_l **stack_b, t_l **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
}

void	rot_a(t_l **stack_a)
{
	ft_rot(stack_a);
	write(1, "ra\n", 3);
}
