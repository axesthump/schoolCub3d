/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 20:05:42 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 15:42:46 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		make_header(unsigned char *bmp_fheader,
unsigned char *bmpinfheader, t_all *all)
{
	int file_size;

	file_size = 14 + 40 + all->window.screen_w * all->window.screen_h *
			all->image.bits_per_pixel / 8;
	bmp_fheader[0] = 'B';
	bmp_fheader[1] = 'M';
	bmp_fheader[2] = (unsigned char)(file_size);
	bmp_fheader[3] = (unsigned char)(file_size >> 8);
	bmp_fheader[4] = (unsigned char)(file_size >> 16);
	bmp_fheader[5] = (unsigned char)(file_size >> 24);
	bmp_fheader[10] = (unsigned char)(14 + 40);
	bmpinfheader[0] = (unsigned char)(40);
	bmpinfheader[4] = (unsigned char)(all->window.screen_w);
	bmpinfheader[5] = (unsigned char)(all->window.screen_w >> 8);
	bmpinfheader[6] = (unsigned char)(all->window.screen_w >> 16);
	bmpinfheader[7] = (unsigned char)(all->window.screen_w >> 24);
	bmpinfheader[8] = (unsigned char)(-all->window.screen_h);
	bmpinfheader[9] = (unsigned char)(-all->window.screen_h >> 8);
	bmpinfheader[10] = (unsigned char)(-all->window.screen_h >> 16);
	bmpinfheader[11] = (unsigned char)(-all->window.screen_h >> 24);
	bmpinfheader[12] = (unsigned char)(1);
	bmpinfheader[14] = (unsigned char)(all->image.bits_per_pixel);
	return (1);
}

static int		write_in_header(unsigned char *bmp_fheader,\
unsigned char *bmpinfheader, t_all *all)
{
	int		fd;
	char	*fname;
	int		line_len;
	int		i;

	i = 0;
	fname = "screenshot.bmp";
	if ((fd = open(fname, O_RDWR | O_CREAT, 0755)) < 0)
		return (0);
	write(fd, bmp_fheader, 14);
	write(fd, bmpinfheader, 40);
	line_len = all->image.bits_per_pixel / 8 * all->window.screen_w;
	while (i < all->window.screen_h)
	{
		write(fd, all->image.addr + i * all->image.line_length, line_len);
		i++;
	}
	if (close(fd < 0))
	{
		ft_putstr_fd("close error", 0);
		return (0);
	}
	return (1);
}

int				ft_make_screen(t_all *all)
{
	unsigned char bmp_fheader[14];
	unsigned char bmpinfheader[40];

	ft_bzero(bmp_fheader, 14);
	ft_bzero(bmpinfheader, 40);
    all->image.img =
	mlx_new_image(all->window.mlx, all->window.screen_w, all->window.screen_h);
	all->image.addr =
	mlx_get_data_addr(all->image.img, &(all->image.bits_per_pixel),
						&(all->image.line_length), &(all->image.endian));
	ft_drow_sky_floor(all);
	ft_drow_3d(all);
	make_header(bmp_fheader, bmpinfheader, all);

	if (!(write_in_header(bmp_fheader, bmpinfheader, all)))
		ft_putstr_fd("scr error\n", 0);
	close(0);
	return (0);
}