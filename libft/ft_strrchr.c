/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:59:27 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/17 22:38:43 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int cha)
{
	int				slen;
	unsigned char	c;

	slen = ft_strlen(s);
	c = (unsigned char) cha;
	while (slen >= 0)
	{
		if (s[slen] == c)
			return ((char *)&s[slen]);
		slen--;
	}
	return (NULL);
}
