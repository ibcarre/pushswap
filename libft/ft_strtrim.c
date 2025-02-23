/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <ibaaziz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:18:00 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/25 13:45:05 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	count_chars(size_t *trimbeg, char const *s1, char const *set)
{
	size_t	i;
	int		count;
	int		len;

	i = 0;
	count = 0;
	len = ft_strlen(s1) - 1;
	while (isset(s1[i], set) && s1[i])
		i++;
	*trimbeg = i;
	if (s1[i] == '\0')
		return (count);
	while (s1[i])
	{
		count++;
		i++;
	}
	while (isset(s1[len], set))
	{
		count--;
		len--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	size_t	trimbeg;
	int		count;
	int		i;

	count = count_chars(&trimbeg, s1, set);
	dst = ft_calloc(sizeof(char), count + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < count)
	{
		dst[i] = s1[trimbeg];
		i++;
		trimbeg++;
	}
	return (dst);
}
/*
int main()
{
	#include <stdio.h>
	char *s = "0000HE00LL000";
	char *set = "0";
	size_t trimbeg = 0;
	printf("%s\n", ft_strtrim(s, set));
	printf("%zu\n", trimbeg);
}*/
