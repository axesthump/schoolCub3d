/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 17:41:43 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 20:40:27 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		ft_add_addr(t_all *all)
{
	if (!(all->texturs.so.addr =
	mlx_get_data_addr(all->texturs.so.img, &(all->texturs.so.bits_per_pixel),
		&(all->texturs.so.line_length), &(all->texturs.so.endian))))
		return (1);
	if (!(all->texturs.no.addr =
	mlx_get_data_addr(all->texturs.no.img, &(all->texturs.no.bits_per_pixel),
		&(all->texturs.no.line_length), &(all->texturs.no.endian))))
		return (1);
	if (!(all->texturs.ea.addr =
	mlx_get_data_addr(all->texturs.ea.img, &(all->texturs.ea.bits_per_pixel),
		&(all->texturs.ea.line_length), &(all->texturs.ea.endian))))
		return (1);
	if (!(all->texturs.we.addr =
	mlx_get_data_addr(all->texturs.we.img, &(all->texturs.we.bits_per_pixel),
		&(all->texturs.we.line_length), &(all->texturs.we.endian))))
		return (1);
	if (!(all->sprite.data.addr =
	mlx_get_data_addr(all->sprite.data.img, &(all->sprite.data.bits_per_pixel),
		&(all->sprite.data.line_length), &(all->sprite.data.endian))))
		return (1);
	return (0);
}

int				ft_init_textures(t_all *all)
{
	if (!(all->texturs.so.img = mlx_xpm_file_to_image(all->window.mlx,
	all->texturs.so.filename, &(all->texturs.so.width),
	&(all->texturs.so.height))))
		return (1);
	if (!(all->texturs.no.img = mlx_xpm_file_to_image(all->window.mlx,
	all->texturs.no.filename, &(all->texturs.no.width),
	&(all->texturs.no.height))))
		return (1);
	if (!(all->texturs.ea.img = mlx_xpm_file_to_image(all->window.mlx,
	all->texturs.ea.filename, &(all->texturs.ea.width),
	&(all->texturs.ea.height))))
		return (1);
	if (!(all->texturs.we.img = mlx_xpm_file_to_image(all->window.mlx,
	all->texturs.we.filename, &(all->texturs.we.width),
	&(all->texturs.we.height))))
		return (1);
	if (!(all->sprite.data.img = mlx_xpm_file_to_image(all->window.mlx,
	all->sprite.filename, &(all->sprite.data.width),
	&(all->sprite.data.height))))
		return (1);
	return (ft_add_addr(all));
}
