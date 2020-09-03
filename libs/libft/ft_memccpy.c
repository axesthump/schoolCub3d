/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 14:57:18 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/06 16:36:46 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)src)[i] == (unsigned char)c)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			return (((unsigned char *)dest) + (i + 1));
		}
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (0);
}
