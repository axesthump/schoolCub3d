/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 22:18:07 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/03 17:34:40 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(long n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len += 1;
	}
	return (len);
}

static char		*ft_getres(char *dest, long num, int index, int sign)
{
	int len;

	len = ft_getlen(num) + sign;
	if (num == 0)
	{
		dest[index] = '0';
		dest[index + 1] = '\0';
		return (dest);
	}
	dest[len] = '\0';
	--len;
	while (len >= index)
	{
		dest[len] = (num % 10) + '0';
		--len;
		num /= 10;
	}
	return (dest);
}

char			*ft_itoa(int n)
{
	long	new_num;
	int		len;
	int		sign;
	char	*res;

	new_num = (long)n;
	len = ft_getlen(new_num);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		new_num *= -1;
	}
	res = (char *)malloc(len + sign + 1);
	if (!res)
		return (NULL);
	n = 0;
	if (sign)
	{
		res[n] = '-';
		++n;
	}
	return (ft_getres(res, new_num, n, sign));
}
