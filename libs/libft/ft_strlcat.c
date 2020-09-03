/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:08:59 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/05 11:01:48 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *s, size_t size)
{
	size_t len;
	size_t i;
	size_t len_dst;

	len_dst = ft_strlen(dst);
	if (len_dst >= size)
		return (ft_strlen(s) + size);
	else
	{
		i = 0;
		len = size - len_dst;
		while (*dst)
			++dst;
		while (s[i] && i < len - 1)
		{
			*dst = s[i];
			++dst;
			++i;
		}
		*dst = '\0';
		return (len_dst + ft_strlen(s));
	}
}
