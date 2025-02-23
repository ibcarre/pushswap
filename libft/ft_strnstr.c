/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:08:42 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/18 00:09:24 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needlen;

	i = 0;
	needlen = ft_strlen(needle);
	if (needlen == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		if (ft_strncmp(&haystack[i], needle, needlen) == 0
			&& i + needlen <= len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	ft_strnstr("AAAAA", "AAAAA", 5);
}*/
