/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 17:02:15 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/03 17:34:10 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	size_t	i;

	i = 0;
	p = malloc(num * size);
	if (!p)
		return (NULL);
	while (i < num * size)
	{
		((unsigned char *)p)[i] = 0;
		++i;
	}
	return (p);
}
