/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:17:58 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/02 22:27:50 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprite_add_back(t_slist **lst, t_slist *new)
{
	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
		(ft_sprite_last(*lst))->next = new;
}

t_slist	*ft_sprite_last(t_slist *sprite)
{
	if (!sprite)
		return(NULL);
	while (sprite->next)
		sprite = sprite->next;
	return(sprite);
}

void		ft_sprite_clear(t_slist *sprite)
{
	t_slist *temp;

	while (sprite)
	{
		temp = sprite->next;
		free(sprite);
		sprite = temp;		
	}
}

t_slist	*ft_sprite_new(double x, double y)
{
	t_slist *el;

	el = (t_slist *)malloc(sizeof(t_slist));
	if (!el)
		return (NULL);
	el->x = x;
	el->y = y;
	el->next = NULL;
	return (el);
}