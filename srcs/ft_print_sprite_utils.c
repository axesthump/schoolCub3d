/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sprite_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:15:47 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 17:20:50 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_print_s_drow(t_all *all, t_s_print *s_prnt)
{
	while (s_prnt->stripe < s_prnt->end_x)
	{
		s_prnt->tex_x = (int)(256 * (s_prnt->stripe - (-(s_prnt->spr_w) / 2 +
		s_prnt->spr_scr_x)) * all->sprite.data.width / s_prnt->spr_w) / 256;
		if (s_prnt->trnsfrm_y > 0 && s_prnt->stripe >= 0
		&& s_prnt->stripe < all->window.screen_w
		&& s_prnt->trnsfrm_y < all->raycast.buffer[s_prnt->stripe])
		{
			s_prnt->y = s_prnt->start_y;
			while (s_prnt->y < s_prnt->end_y)
			{
				s_prnt->d = (s_prnt->y) * 256
				- all->window.screen_h * 128 + s_prnt->spr_h * 128;
				s_prnt->tex_y = ((s_prnt->d * all->sprite.data.height)
								/ s_prnt->spr_h) / 256;
				s_prnt->color = ft_get_pixel_color(&(all->sprite.data),
										s_prnt->tex_x, s_prnt->tex_y);
				if ((s_prnt->color & 0x00FFFFFF) != 0)
					ft_pixel_put(&(all->image), s_prnt->stripe,
									s_prnt->y, s_prnt->color);
				(s_prnt->y)++;
			}
		}
		(s_prnt->stripe)++;
	}
}

t_slist			*ft_sort_sprite(t_slist *head)
{
	t_slist		*new_root;
	t_slist		*node;
	t_slist		*current;

	new_root = NULL;
	while (head != NULL)
	{
		node = head;
		head = head->next;
		if (new_root == NULL || node->dist > new_root->dist)
		{
			node->next = new_root;
			new_root = node;
		}
		else
		{
			current = new_root;
			while (current->next != NULL && !(node->dist > current->next->dist))
				current = current->next;
			node->next = current->next;
			current->next = node;
		}
	}
	return (new_root);
}
