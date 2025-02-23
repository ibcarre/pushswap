/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:39:11 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/23 13:11:03 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_int(char *nb)
{
	int	i;

	i = 0;
	while (nb[i] == '+' || nb[i] == '-')
		i++;
	if (nb[i] == 0)
		return (0);
	while (nb[i])
	{
		if (!ft_isdigit(nb[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_dup(t_l *head)
{
	t_l	*index;

	if (!head || !(head->next))
		return (0);
	index = head->next;
	while (head->next)
	{
		while (index)
		{
			if (index->content == head->content)
				return (-1);
			index = index->next;
		}
		head = head->next;
		index = head->next;
	}
	return (0);
}

int	ft_create_stack(char **nb, t_l **stack_a)
{
	int	i;
	t_l	*temp;

	i = -1;
	if (!nb[0])
		return (-1);
	while (nb[++i])
	{
		if (check_int(nb[i]) == 0 || ft_atoi(nb[i]) < INT_MIN
			|| ft_atoi(nb[i]) > INT_MAX)
			return (-1);
		if (!(*stack_a))
		{
			*stack_a = ft_lstnew(ft_atoi(nb[i]));
			if (!(*stack_a))
				return (-1);
		}
		else
		{
			temp = ft_lstnew(ft_atoi(nb[i]));
			if (!temp)
				return (-1);
			ft_lstadd_back(stack_a, temp);
		}
	}
	return (0);
}
