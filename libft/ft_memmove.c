/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:06:29 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/20 12:34:29 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*dst;
	char	*srcc;

	if (!src && !dest)
		return (NULL);
	dst = (char *) dest;
	srcc = (char *) src;
	i = 0;
	if (src < dest)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			dst[i] = srcc[i];
			i--;
		}
		return (dest);
	}
	while ((size_t)i < n)
	{
		dst[i] = srcc[i];
		i++;
	}
	return (dest);
}

/*
int main()
{
	printf("TEST\n");
	char *str = "thanks to @apellicc for this test !\r\n";
	char dst[100];
	//printf("%s\n", (char *)memmove(dst, str, 37));
	printf("TEST\n");
	printf("%s\n", (char *)ft_memmove("", "" - 1, 0));
}*/
