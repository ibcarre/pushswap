/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibaaziz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 13:45:22 by ibaaziz           #+#    #+#             */
/*   Updated: 2024/11/22 19:17:39 by ibaaziz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(long n)
{
	int	count;

	count = 0;
	if (n < 10)
	{
		count++;
		return (count);
	}
	count ++;
	return (count + count_nbr(n / 10));
}

static void	ft_fill(char *str, long n, int sign)
{
	int				i;
	unsigned char	c;

	i = 0;
	if (n < 10)
	{
		c = n + '0';
		if (sign)
		{
			str[0] = '-';
			str[1] = c;
		}
		else
			str[0] = c;
		return ;
	}
	ft_fill(str, n / 10, sign);
	while (str[i])
		i++;
	c = n % 10 + '0';
	str[i] = c;
}

char	*ft_itoa(int n)
{
	int		count;
	long	nb;
	char	*str;
	int		sign;

	sign = 0;
	nb = n;
	if (nb < 0)
	{
		sign = 1;
		nb = nb * (-1);
	}
	count = count_nbr(nb);
	str = ft_calloc(count + sign + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_fill(str, nb, sign);
	return (str);
}
/*
int main()
{
#include <stdio.h>
	printf("%s\n", ft_itoa(-2147483648LL));
}
*/
