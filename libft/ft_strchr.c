/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:44:19 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/17 22:52:35 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int cha)
{
	unsigned char	c;
	int				i;

	i = 0;
	c = (unsigned char) cha;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i ++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
