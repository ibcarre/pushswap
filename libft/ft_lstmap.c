/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 09:58:10 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/30 10:21:21 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*new;
	t_list	*scan;
	t_list	*scannew;

	scan = lst;
	new = malloc(sizeof(t_list));
	if (!lst || !new)
		return (NULL);
	scannew = new;
	while (scan)
	{
		scannew -> content = f(scan -> content);
		if (scan -> next)
		{
			scannew -> next = malloc(sizeof(t_list));
			if (!scannew -> next)
				return (ft_lstclear(&new, del), NULL);
			scannew = scannew -> next;
		}
		scan = scan -> next;
	}
	scannew -> next = NULL;
	return (new);
}
