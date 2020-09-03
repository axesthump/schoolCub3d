/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 20:36:13 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/03 11:11:47 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	t_slist	*ft_sort_sprite(t_slist *head)
{
	t_slist *new_root;
	t_slist *node;
	t_slist *current;

	new_root = NULL;
    while (head != NULL)
    {
        node = head;
        head = head->next;
        if ( new_root == NULL || node->dist > new_root->dist )
        {
            node->next = new_root;
            new_root = node;
        }
        else
        {
            current = new_root;
            while ( current->next != NULL && !( node->dist > current->next->dist ) )
                  current = current->next;
            node->next = current->next;
            current->next = node;
        }
    }
    return new_root;
}

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

static	void	ft_print_s(t_all *all, t_slist *sprite, t_textur_info *data)
{
	t_raycast *ray = &(all->raycast);
	t_plr		*plr = &(all->player);
	double spr_x = sprite->x - plr->x;
	double spr_y = sprite->y - plr->y;
	double inv_det = 1.0 / \
		(plr->plane_x * plr->p_dir_y - plr->p_dir_x * plr->plane_y);
	double trnsfrm_x = inv_det * \
		(plr->p_dir_y * spr_x - plr->p_dir_x * spr_y);
	double trnsfrm_y = inv_det * \
		(-plr->plane_y * spr_x + plr->plane_x * spr_y);
	int spr_scr_x = (int)((all->window.screen_w / 2) * \
		(1 + trnsfrm_x / trnsfrm_y));
	double v_move_scr = (int)(VMOVE / trnsfrm_y);
	int spr_h = abs((int)(((all->window.screen_h / (trnsfrm_y))))); //* VDIV

	//y_calcs
	int	 start_y =  -spr_h / 2 + \
			all->window.screen_h / 2; //+ v_move_scr
	if (start_y < 0)
		start_y = 0;
	int	 end_y = spr_h / 2 + \
		all->window.screen_h / 2; //+ v_move_scr
	if (end_y >= all->window.screen_h)
		end_y = all->window.screen_h - 1;
	//y_calcs end

	int spr_w = abs((int)(((all->window.screen_h / (trnsfrm_y))))); //* UDIV
	int	 start_x = -spr_w / 2 + spr_scr_x;
	if (start_x < 0)
		start_x = 0;
	int end_x = spr_w / 2 + spr_scr_x;
	if (end_x >= all->window.screen_w)
		end_x = all->window.screen_w - 1;
	
	//drow_sprite
	int	stripe;

	stripe = start_x;
	while (stripe < end_x)
	{
		int tex_x = (int)(256 * (stripe - (-spr_w / 2 + \
		spr_scr_x)) * all->sprite.data.width / spr_w) / 256;
		if (trnsfrm_y > 0 && stripe > 0 && stripe < all->window.screen_w && trnsfrm_y < all->raycast.buffer[stripe])
		{
			//drow_sprite_y
			int		y;
			int		d;
			int		color;

			y = start_y;
			while (y < end_y)
			{
				d = (y) * 256\
				- all->window.screen_h * 128 + spr_h * 128; // - v_move_scr
				int tex_y = ((d * all->sprite.data.height) / spr_h) / 256;
				color = ft_get_pixel_color(&(all->sprite.data), tex_x, tex_y);
				if ((color & 0x00FFFFFF) != 0)
					ft_pixel_put(&(all->image), stripe, y, color);
				y++;
			}
			//
		}
		stripe++;
	}
	//
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