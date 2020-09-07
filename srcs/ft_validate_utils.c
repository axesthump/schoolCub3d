/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:48:54 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 21:12:50 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int				ft_check_nswe(t_all *all, char *row, int *change)
{
	int err;

	if (row[0] == 'S' && (*change = 1))
	{
		if ((err = ft_get_sprite_or_so(all, row)) < 0)
			return (err);
	}
	else if (row[0] == 'N' && (*change = 1))
	{
		if ((err = ft_get_no(all, row)) < 0)
			return (err);
	}
	else if (row[0] == 'E' && (*change = 1))
	{
		if ((err = ft_get_ea(all, row)) < 0)
			return (err);
	}
	else if (row[0] == 'W' && (*change = 1))
	{
		if ((err = ft_get_we(all, row)) < 0)
			return (err);
	}
	else
		return (0);
	return (0);
}

int				ft_is_start_map(char *row)
{
	while (*row)
	{
		if (*row == ' ' || *row == '1' || *row == '2' || *row == 'N'
		|| *row == 'S' || *row == 'W' || *row == 'E' || *row == '0')
			++row;
		else
			return (0);
	}
	return (1);
}

int				ft_get_f(t_all *all, char *row)
{
	long	r;
	long	g;
	long	b;

	if (ft_get_rgb(&r, &g, &b, row) < 0)
		return (-4);
	all->validate.f += 1;
	if (all->validate.f > 1)
		return (-1);
	all->window.floor_color = r << 16 | g << 8 | b << 0;
	return (0);
}

int				ft_get_c(t_all *all, char *row)
{
	long	r;
	long	g;
	long	b;

	if (ft_get_rgb(&r, &g, &b, row) < 0)
		return (-4);
	all->validate.c += 1;
	if (all->validate.c > 1)
		return (-1);
	all->window.ceilling_color = r << 16 | g << 8 | b << 0;
	return (0);
}

int				ft_get_rgb(long *r, long *g, long *b, char *row)
{
	if (row[0] != ' ' || ft_check_last_symbol(row, 0) == -1)
		return (-4);
	while (*row == ' ')
		++row;
	if (!(ft_isdigit((*row))))
		return (-4);
	if (!(row = ft_init_color(row, r)))
		return (-4);
	if (!(row = ft_init_color(row, g)))
		return (-4);
	row = ft_init_color(row, b);
	if (*r < 0 || *g < 0 || *b < 0)
		return (-4);
	return (0);
}
