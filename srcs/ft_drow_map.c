/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drow_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:20:37 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 20:38:15 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_drow_sky_floor(t_all *all)
{
	int half;
	int i;
	int	j;

	half = all->window.screen_h / 2;
	i = 0;
	while (i < half)
	{
		j = -1;
		while (++j < all->window.screen_w)
			ft_pixel_put(&(all->image), j, i, all->window.ceilling_color);
		++i;
	}
	while (i < all->window.screen_h)
	{
		j = -1;
		while (++j < all->window.screen_w)
			ft_pixel_put(&(all->image), j, i, all->window.floor_color);
		++i;
	}
}

int				ft_drow_map(t_all *all)
{
	all->image.img =
	mlx_new_image(all->window.mlx, all->window.screen_w, all->window.screen_h);
	all->image.addr =
	mlx_get_data_addr(all->image.img, &(all->image.bits_per_pixel),
						&(all->image.line_length), &(all->image.endian));
	ft_drow_sky_floor(all);
	ft_drow_3d(all);
	mlx_put_image_to_window(all->window.mlx,
							all->window.win, all->image.img, 0, 0);
	return (1);
}
