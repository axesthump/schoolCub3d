/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 19:23:36 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 19:27:08 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int		ft_lstsize(t_list *lst)
{
	int		len;

	if (!lst)
		return (0);
	len = 0;
	while (lst)
	{
		++len;
		lst = lst->next;
	}
	return (len);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		++i;
	}
	return (s);
}
