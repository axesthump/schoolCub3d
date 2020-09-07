/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_3d_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:57:24 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 20:22:59 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_r_init(t_raycast *r, t_all *all, int x_pix)
{
	r->camera_x = 2 * x_pix / (double)(all->window.screen_w) - 1;
	r->ray_dir_x = all->player.p_dir_x + all->player.plane_x * r->camera_x;
	r->ray_dir_y = all->player.p_dir_y + all->player.plane_y * r->camera_x;
	r->mapX = (int)(all->player.x);
	r->mapY = (int)(all->player.y);
	r->hit = 0;
}
