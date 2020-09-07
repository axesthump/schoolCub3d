/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 18:38:22 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 21:01:08 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_get_values(t_all *all, t_raycast *r, int line_height)
{
	all->print.wall_x -= floor(all->print.wall_x);
	all->print.text_x = (int)(all->print.wall_x * (double)all->print.text_w);
	if (r->side == 2 || r->side == 1)
		all->print.text_x = all->print.text_w - all->print.text_x - 1;
	all->print.step = 1.0 * all->print.text_h / line_height;
	all->print.tex_pos = (r->drawStart -
				all->window.screen_h / 2 + line_height / 2) * all->print.step;
	all->print.y = r->drawStart;
	all->print.shade = 1 / (1 + 0.005 * r->perp_wall_dist + 0.006 * \
		pow(r->perp_wall_dist, 2));
}

int				ft_get_pixel_color(t_textur_info *img, int x, int y)
{
	if (!(img->width) || !img->height)
		return (0);
	x = abs(x);
	y = abs(y);
	if (x > img->width || y > img->height || x < 0 || y < 0)
		return (0);
	return (*(int*)(img->addr + ((x + (y * img->width))\
			* (img->bits_per_pixel / 8))));
}

static	void	ft_check_side_2_and_3(t_all *all)
{
	if (all->raycast.side == 2 || all->raycast.side == 3)
		all->print.wall_x = all->player.y +
		all->raycast.perp_wall_dist * all->raycast.ray_dir_y;
	else
		all->print.wall_x = all->player.x +
		all->raycast.perp_wall_dist * all->raycast.ray_dir_x;
}

static	void	ft_get_textur_width_height(t_all *all)
{
	if (all->raycast.side == 0)
	{
		all->print.text_w = all->texturs.so.width;
		all->print.text_h = all->texturs.so.height;
	}
	if (all->raycast.side == 1)
	{
		all->print.text_w = all->texturs.no.width;
		all->print.text_h = all->texturs.no.height;
	}
	if (all->raycast.side == 2)
	{
		all->print.text_w = all->texturs.ea.width;
		all->print.text_h = all->texturs.ea.height;
	}
	if (all->raycast.side == 3)
	{
		all->print.text_w = all->texturs.we.width;
		all->print.text_h = all->texturs.we.height;
	}
	ft_check_side_2_and_3(all);
}

void			ft_print(t_all *all, int line_height, int x_pix)
{
	t_raycast *r;

	r = &(all->raycast);
	ft_get_textur_width_height(all);
	ft_get_values(all, r, line_height);
	while (all->print.y < r->drawEnd)
	{
		all->print.text_y = (int)(all->print.tex_pos) & (all->print.text_h - 1);
		if (r->side == 0)
			all->print.color = ft_get_pixel_color(&(all->texturs.so),
			all->print.text_x, all->print.text_y);
		else if (r->side == 1)
			all->print.color = ft_get_pixel_color(&(all->texturs.no),
			all->print.text_x, all->print.text_y);
		else if (r->side == 2)
			all->print.color = ft_get_pixel_color(&(all->texturs.ea),
			all->print.text_x, all->print.text_y);
		else if (r->side == 3)
			all->print.color = ft_get_pixel_color(&(all->texturs.we),
			all->print.text_x, all->print.text_y);
		all->print.tex_pos += all->print.step;
		ft_pixel_put(&(all->image), x_pix, all->print.y, all->print.color);
		all->print.y++;
	}
}
