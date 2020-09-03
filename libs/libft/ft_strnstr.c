/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 00:43:22 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/03 17:34:10 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;
	size_t tmp;

	i = 0;
	if (!str2[i])
		return ((char *)str1);
	else
	{
		while (str1[i] && i < n)
		{
			j = 0;
			tmp = i;
			while (str1[i] == str2[j] && str1[i] && str2[j] && i < n)
			{
				++i;
				++j;
			}
			if (!(str2[j]))
				return ((char *)(str1 + tmp));
			i = tmp;
			++i;
		}
		return (0);
	}
}
