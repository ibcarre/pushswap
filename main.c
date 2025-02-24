/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 23:36:28 by ibaaziz           #+#    #+#             */
/*   Updated: 2025/02/24 13:18:41 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_err(char **str, t_l *s)
{
	if (str)
		ft_free(str);
	ft_freelst(s);
	write(2, "Error\n", 6);
	return (2);
}

/*
void ft_print(t_l *stack, char *str)
{
	printf("%s\n", str);
	while (stack)
	{
		printf("%i\n", stack->content);
		stack = stack -> next;
	}
}*/

int	is_ordered(t_l *stack)
{
	t_l	*head;

	head = stack;
	while (stack -> next)
	{
		if (stack -> content > (stack->next)->content)
			return (0);
		stack = stack -> next;
	}
	ft_freelst(head);
	exit (1);
}

int	main(int av, char **argc)
{
	int		i;
	char	**nbs;
	t_l		*stack_a;
	t_l		*stack_b;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (av == 1)
		return (0);
	while (argc[i])
	{
		nbs = ft_split(argc[i], ' ');
		if (ft_create_stack(nbs, &stack_a) == -1)
			return (ft_err(nbs, stack_a));
		ft_free(nbs);
		i++;
	}
	if (check_dup(stack_a) == -1 || is_ordered(stack_a))
		return (ft_err(NULL, stack_a));
	if (av == 3 || av == 4)
		return (sort_three(&stack_a), 0);
	sort(&stack_a, &stack_b);
	return (0);
}
