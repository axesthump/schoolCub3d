/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 18:49:49 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/06 15:19:24 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *p;
	t_list *tmp;

	if (!del)
		return ;
	p = *lst;
	while (p)
	{
		tmp = p->next;
		ft_lstdelone(p, del);
		p = tmp;
	}
	*lst = NULL;
}
