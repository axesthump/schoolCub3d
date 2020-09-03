/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 00:52:00 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/06 16:55:52 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	int		len;
	void	*el;

	if (!lst || !f)
		return (NULL);
	len = ft_lstsize(lst) - 1;
	if (!(el = (f)(lst->content)))
		return (NULL);
	res = ft_lstnew((f)(lst->content));
	lst = lst->next;
	while (len)
	{
		el = (f)(lst->content);
		if (!el)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, ft_lstnew(el));
		lst = lst->next;
		--len;
	}
	return (res);
}
