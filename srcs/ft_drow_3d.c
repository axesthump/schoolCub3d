/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:15:39 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/03 10:18:14 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_get_delta_x_y(t_raycast *r)
{
	if (!(r->ray_dir_y))
		r->delta_dist_x = 0;
	else
		r->delta_dist_x = (!(r->ray_dir_x)) ? 1 : fabs(1 / r->ray_dir_x);
	if (!(r->ray_dir_x))
		r->delta_dist_y = 0;
	else
		r->delta_dist_y = (!(r->ray_dir_y)) ? 1 : fabs(1 / r->ray_dir_y);
}

void			ft_get_side_dist_x_y_and_step (t_raycast *r, double x, double y)
{
	if (r->ray_dir_x < 0)
	{
		r->stepX = -1;
		r->side_dist_x = (x - r->mapX) * r->delta_dist_x;
	}
	else
	{
		r->stepX = 1;
		r->side_dist_x = (1.0 + r->mapX - x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->stepY = -1;
		r->side_dist_y = (y - r->mapY) * r->delta_dist_y;
	}
	else
	{
		r->stepY = 1;
		r->side_dist_y = (1.0 + r->mapY - y) * r->delta_dist_y;
	}
}

void			ft_check_hit(t_raycast *r, char **map, t_all *all)
{
	while (r->hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->mapX += r->stepX;
			r->side = (r->ray_dir_x < 0) ? 2 : 3;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->mapY += r->stepY;
			r->side = (r->ray_dir_y < 0) ? 0 : 1;
		}
		if (map[r->mapY][r->mapX] == '1')
		{
			r->hit = 1;
		}
	}
}

void			ft_get_wall_height(t_all *all, int *line_height)
{
	t_raycast *r = &(all->raycast);
	if (r->side > 1) 
		r->perp_wall_dist = (r->mapX - all->player.x + (1 - r->stepX) / 2) / r->ray_dir_x;
	else 
		r->perp_wall_dist = (r->mapY - all->player.y + (1 - r->stepY) / 2) / r->ray_dir_y;
	*line_height = (int)(all->window.screen_h / r->perp_wall_dist);
	r->drawStart = -(*line_height) / 2 + all->window.screen_h / 2;
	if (r->drawStart < 0)
		r->drawStart = 0;
	r->drawEnd = *line_height / 2 + all->window.screen_h / 2;
	if (r->drawEnd >= all->window.screen_h)
		r->drawEnd = all->window.screen_h - 1;
}

void			ft_drow_3d(t_all *all)
{
	t_plr		plr;
	char		**map;
	t_raycast 	*r;
	int			x_pix;
	int			line_height;

	plr = all->player;
	map = all->window.map;
	r = &(all->raycast);
	x_pix = -1;
	while (++x_pix < all->window.screen_w)
	{
		ft_r_init(r, all, x_pix);
		ft_get_delta_x_y(r);
		ft_get_side_dist_x_y_and_step(r, plr.x, plr.y);
		ft_check_hit(r, map, all);
		ft_get_wall_height(all, &line_height);
		ft_print(all, line_height, x_pix);
		all->raycast.buffer[x_pix] = all->raycast.perp_wall_dist;
	}
	ft_print_sprite(all);
}