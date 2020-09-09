/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 20:41:40 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 16:33:07 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_move_w_s(t_all *all)
{
	if (all->move.w)
	{
		if (ft_check_step(all->window.map, (int)all->player.y,
			(int)(all->player.x + all->player.p_dir_x * (SPEED + 0.01))))
			all->player.x += all->player.p_dir_x * SPEED;
		if (ft_check_step(all->window.map,
			(int)(all->player.y + all->player.p_dir_y * (SPEED + 0.01)),\
			(int)all->player.x))
			all->player.y += all->player.p_dir_y * SPEED;
	}
	if (all->move.s)
	{
		if (ft_check_step(all->window.map, (int)all->player.y,\
			(int)(all->player.x - all->player.p_dir_x * (SPEED + 0.01))))
			all->player.x -= all->player.p_dir_x * SPEED;
		if (ft_check_step(all->window.map,
			(int)(all->player.y - all->player.p_dir_y * (SPEED + 0.01)),\
			(int)all->player.x))
			all->player.y -= all->player.p_dir_y * SPEED;
	}
}

void			ft_move_a_d(t_all *all)
{
	if (all->move.a)
	{
		if (ft_check_step(all->window.map, (int)all->player.y,\
			(int)(all->player.x - all->player.plane_x * (SPEED + 0.01))))
			all->player.x -= all->player.plane_x * SPEED;
		if (ft_check_step(all->window.map,
			(int)(all->player.y - all->player.plane_y * (SPEED + 0.01)),\
			(int)all->player.x))
			all->player.y -= all->player.plane_y * SPEED;
	}
	if (all->move.d)
	{
		if (ft_check_step(all->window.map, (int)all->player.y,\
			(int)(all->player.x + all->player.plane_x * (SPEED + 0.01))))
			all->player.x += all->player.plane_x * SPEED;
		if (ft_check_step(all->window.map,
			(int)(all->player.y + all->player.plane_y * (SPEED + 0.01)),\
			(int)all->player.x))
			all->player.y += all->player.plane_y * SPEED;
	}
}

static	void	ft_turn_r(t_all *all)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = all->player.p_dir_x;
	all->player.p_dir_x = all->player.p_dir_x * cos(0.05) -
		all->player.p_dir_y * sin(0.05);
	all->player.p_dir_y = old_dir_x * sin(0.05)
		+ all->player.p_dir_y * cos(0.05);
	old_plane_x = all->player.plane_x;
	all->player.plane_x = all->player.plane_x * cos(0.05)
		- all->player.plane_y * sin(0.05);
	all->player.plane_y = old_plane_x * sin(0.05)
		+ all->player.plane_y * cos(0.05);
}

void			ft_turn_l_r(t_all *all)
{
	double old_dir_x;
	double old_plane_x;

	if (all->move.l_arr)
	{
		old_dir_x = all->player.p_dir_x;
		all->player.p_dir_x = all->player.p_dir_x * cos(-0.05)
			- all->player.p_dir_y * sin(-0.05);
		all->player.p_dir_y = old_dir_x * sin(-0.05)
			+ all->player.p_dir_y * cos(-0.05);
		old_plane_x = all->player.plane_x;
		all->player.plane_x = all->player.plane_x * cos(-0.05)
			- all->player.plane_y * sin(-0.05);
		all->player.plane_y = old_plane_x * sin(-0.05) +
			all->player.plane_y * cos(-0.05);
	}
	if (all->move.r_arr)
		ft_turn_r(all);
}

int				ft_check_step(char **map, int y, int x)
{
	if (map[y][x] == ' ' || map[y][x] == '0'
	|| map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
		|| map[y][x] == 'E')
		return (1);
	return (0);
}