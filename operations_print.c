/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:58:12 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/01/27 23:12:39 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_l **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
	//printf("sa\n");
}

void	swap_b(t_l **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
	//printf("sb\n");
}

void	push_a(t_l **stack_a, t_l **stack_b) ////
{
	push(stack_a, stack_b);
	write(1, "pa\n", 3);
	//printf("pa\n");
}

void	push_b(t_l **stack_b, t_l **stack_a) //
{
	push(stack_b, stack_a);
	write(1, "pb\n", 3);
	//printf("pb\n");
}

void	rot_a(t_l **stack_a)
{
	ft_rot(stack_a);
	write(1, "ra\n", 3);
}

void	rot_b(t_l **stack_b) //
{
	ft_rot(stack_b);
	write(1, "rb\n", 3);
}

void	rot_d(t_l **stack_a, t_l **stack_b) //
{
	ft_rot_d(stack_a, stack_b);
	write(1, "rr\n", 3);
}

void	revrot_a(t_l **stack_a) ///
{
	ft_revrot(stack_a);
	write(1, "rra\n", 4);
}

void	revrot_b(t_l **stack_b) ///
{
	ft_revrot(stack_b);
	write(1, "rrb\n", 4);
}

void	revrot_d(t_l **stack_a, t_l **stack_b) ///
{
	ft_revrot_d(stack_a, stack_b);
	write(1, "rrr\n", 4);
}
