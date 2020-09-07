/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:36:13 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 21:02:05 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_get_sprite_dist(t_all *all)
{
	t_slist *head;

	head = all->sprite.el;
	while (head)
	{
		head->dist = sqrt(pow(all->player.x - head->x, 2) + \
						pow(all->player.y - head->y, 2));
		head = head->next;
	}
}

static	void	ft_print_s_init(t_all *all,
				t_s_print *s_prnt, t_slist *sprite, t_plr *plr)
{
	s_prnt->spr_x = sprite->x - plr->x;
	s_prnt->spr_y = sprite->y - plr->y;
	s_prnt->inv_det = 1.0 / \
		(plr->plane_x * plr->p_dir_y - plr->p_dir_x * plr->plane_y);
	s_prnt->trnsfrm_x = s_prnt->inv_det * \
		(plr->p_dir_y * s_prnt->spr_x - plr->p_dir_x * s_prnt->spr_y);
	s_prnt->trnsfrm_y = s_prnt->inv_det * \
		(-plr->plane_y * s_prnt->spr_x + plr->plane_x * s_prnt->spr_y);
	s_prnt->spr_scr_x = (int)((all->window.screen_w / 2) * \
		(1 + s_prnt->trnsfrm_x / s_prnt->trnsfrm_y));
	s_prnt->spr_h = abs((int)(((all->window.screen_h / (s_prnt->trnsfrm_y)))));
	s_prnt->start_y = -(s_prnt->spr_h) / 2 + \
			all->window.screen_h / 2;
	if (s_prnt->start_y < 0)
		s_prnt->start_y = 0;
	s_prnt->end_y = (s_prnt->spr_h) / 2 + \
		all->window.screen_h / 2;
	if (s_prnt->end_y >= all->window.screen_h)
		s_prnt->end_y = all->window.screen_h - 1;
}

static	void	ft_print_s_get_start_and_end_and_stripe(t_all *all,
				t_s_print *s_prnt)
{
	s_prnt->spr_w = abs((int)(((all->window.screen_h / (s_prnt->trnsfrm_y)))));
	s_prnt->start_x = -(s_prnt->spr_w) / 2 + s_prnt->spr_scr_x;
	if (s_prnt->start_x < 0)
		s_prnt->start_x = 0;
	s_prnt->end_x = s_prnt->spr_w / 2 + s_prnt->spr_scr_x;
	if (s_prnt->end_x >= all->window.screen_w)
		s_prnt->end_x = all->window.screen_w - 1;
	s_prnt->stripe = s_prnt->start_x;
}

static	void	ft_print_s(t_all *all, t_slist *sprite, t_textur_info *data)
{
	t_raycast	*ray;
	t_plr		*plr;
	t_s_print	*s_prnt;

	ray = &(all->raycast);
	plr = &(all->player);
	s_prnt = &(all->s_print);
	ft_print_s_init(all, s_prnt, sprite, plr);
	ft_print_s_get_start_and_end_and_stripe(all, s_prnt);
	ft_print_s_drow(all, s_prnt);
}

void			ft_print_sprite(t_all *all)
{
	t_slist *head;
	t_slist *temp;

	head = all->sprite.el;
	if (head)
	{
		ft_get_sprite_dist(all);
		head = ft_sort_sprite(head);
		all->sprite.el = head;
		temp = head;
		while (temp)
		{
			ft_print_s(all, temp, &(all->sprite.data));
			temp = temp->next;
		}
	}
}
