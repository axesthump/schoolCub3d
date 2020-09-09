/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:50:43 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 18:53:10 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
{
	t_list *el;

	el = (t_list *)malloc(sizeof(t_list));
	if (!el)
		return (NULL);
	el->content = content;
	el->next = NULL;
	return (el);
}
