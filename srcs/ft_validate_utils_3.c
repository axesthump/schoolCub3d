/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_utils_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:57:21 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 21:14:48 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_get_sprite_or_so(t_all *all, char *row)
{
	if (row[1] != ' ' && row[1] != 'O')
		return (-2);
	else
	{
		if (row[1] == ' ')
		{
			if ((ft_get_sprite_texture(all, row + 1)) < 0)
				return (-3);
			else
				return (0);
		}
		else
		{
			if ((ft_get_so_texture(all, row + 2)) < 0)
				return (-3);
			else
				return (0);
		}
	}
}

int				ft_get_so_texture(t_all *all, char *row)
{
	int fd;

	if (ft_check_last_symbol(row, 0) == -1)
		return (-1);
	while (*row == ' ')
		++row;
	if ((fd = open(row, O_RDONLY)) == -1)
		return (-1);
	all->texturs.so.filename = row;
	all->validate.so += 1;
	close(fd);
	if (all->validate.so != 1)
		return (-1);
	return (0);
}

int				ft_get_sprite_texture(t_all *all, char *row)
{
	int fd;

	if (ft_check_last_symbol(row, 0) == -1)
		return (-1);
	while (*row == ' ')
		++row;
	if ((fd = open(row, O_RDONLY)) == -1)
		return (-1);
	all->sprite.filename = row;
	all->validate.s += 1;
	close(fd);
	if (all->validate.s != 1)
		return (-1);
	return (0);
}

int				ft_get_screen(t_all *all, char *row)
{
	if (row[1] != ' ' || ft_check_last_symbol(row, 1) == -1)
		return (-1);
	else
	{
		row++;
		while (*row == ' ' && *row)
			++row;
		if (!(*row) || !ft_isdigit(*row))
			return (-1);
		all->window.screen_w = ft_atoi(row);
		while (ft_isdigit(*row))
			++row;
		while (*row == ' ' && *row)
			++row;
		if (!(*row) || !ft_isdigit(*row))
			return (-1);
		all->window.screen_h = ft_atoi(row);
		ft_get_screen_max_size(all);
		return (all->validate.r == 1 ? 0 : -1);
	}
}

void			ft_get_screen_max_size(t_all *all)
{
	int width;
	int height;

	mlx_get_screen_size(all->window.mlx, &width, &height);
	if (all->window.screen_w > width)
		all->window.screen_w = width;
	if (all->window.screen_h > height)
		all->window.screen_h = height;
	if (all->window.screen_w == 0)
		all->window.screen_w = 640;
	if (all->window.screen_h == 0)
		all->window.screen_h = 480;
	all->validate.r += 1;
}
