/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:36:11 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/26 17:35:03 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (len > ft_strlen(s) - start && start <= ft_strlen(s))
		sub = malloc(ft_strlen(s) - start + 1 * sizeof(char));
	else if (start <= ft_strlen(s))
		sub = malloc(len + 1 * sizeof(char));
	else
		sub = malloc(1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && i + start < ft_strlen(s))
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

/*
int main()
{
	char *s = "0123456789";
	ft_substr(s, 9, 10);
}*/
