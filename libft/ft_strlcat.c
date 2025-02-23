/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:11:57 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/23 12:18:56 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	j;
	size_t	init_dest;

	init_dest = ft_strlen(dst);
	if (siz <= init_dest)
		return (ft_strlen(src) + siz);
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (i < siz - 1 && src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src) + init_dest);
}
