/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:20:37 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/02 18:16:13 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_drow_sky_floor(t_all *all)
{
	int screen_h = 800;
	int screen_w = 1200;

	int half = screen_h / 2;
	int i = 0;
	while (i < half)
	{
		for (int j = 0; j < screen_w; ++j)
			ft_pixel_put(&(all->image), j, i, 0x99CCFF);
		++i;
	}
	while (i < screen_h)
	{
		for (int j = 0; j < screen_w; ++j)
			ft_pixel_put(&(all->image), j, i, 0x996633);
		++i;
	}
}

void			ft_drow_map(t_all *all)
{
	all->image.img = mlx_new_image(all->window.mlx, all->window.screen_w, all->window.screen_h);
	all->image.addr = mlx_get_data_addr(all->image.img, &(all->image.bits_per_pixel),
						&(all->image.line_length), &(all->image.endian));
	ft_drow_sky_floor(all);
	ft_drow_3d(all);

	mlx_put_image_to_window(all->window.mlx, all->window.win, all->image.img, 0, 0);
}