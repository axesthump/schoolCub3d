/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:17:25 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/03 22:10:38 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_check_step(char **map, int y, int x)
{
	if (map[y][x] == ' ' || map[y][x] == '0'
	|| map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
		|| map[y][x] == 'E')
		return (1);
	return (0);
}

static	void	ft_move_w_s(t_all *all)
{
	if (all->move.w)
	{
		if (ft_check_step(all->window.map, (int)all->player.y, (int)(all->player.x + all->player.p_dir_x * SPEED + 0.001)))
			all->player.x += all->player.p_dir_x * SPEED;
		if (ft_check_step(all->window.map, (int)(all->player.y + all->player.p_dir_y * SPEED + 0.001),\
		(int)all->player.x))
			all->player.y += all->player.p_dir_y * SPEED;
	}
	if (all->move.s)
	{
		if (ft_check_step(all->window.map, (int)all->player.y,\
		(int)(all->player.x - all->player.p_dir_x * SPEED + 0.001)))
			all->player.x -= all->player.p_dir_x * SPEED;
		if (ft_check_step(all->window.map, (int)(all->player.y - all->player.p_dir_y * SPEED + 0.001),\
		(int)all->player.x))
			all->player.y -= all->player.p_dir_y * SPEED;
	}
}

static	void	ft_move_a_d(t_all *all)
{
	if (all->move.a)
	{
		if (ft_check_step(all->window.map, (int)all->player.y,\
		(int)(all->player.x - all->player.plane_x * SPEED + 0.001)))
			all->player.x -= all->player.plane_x * SPEED;
		if (ft_check_step(all->window.map, (int)(all->player.y - all->player.plane_y * SPEED + 0.001),\
		(int)all->player.x))
			all->player.y -= all->player.plane_y * SPEED;
	}
	if (all->move.d)
	{
		if (ft_check_step(all->window.map, (int)all->player.y,\
		(int)(all->player.x + all->player.plane_x * SPEED + 0.001)))
			all->player.x += all->player.plane_x * SPEED;
		if (ft_check_step(all->window.map, (int)(all->player.y + all->player.plane_y * SPEED + 0.001),\
		(int)all->player.x))
			all->player.y += all->player.plane_y * SPEED;
	}
}

static	void	ft_turn_l_r(t_all *all)
{
	if (all->move.l_arr)
	{
		double old_dir_x;
		double old_plane_x;

		old_dir_x = all->player.p_dir_x;
		all->player.p_dir_x = all->player.p_dir_x * cos(-0.05) - all->player.p_dir_y * sin(-0.05);
		all->player.p_dir_y = old_dir_x * sin(-0.05) + all->player.p_dir_y * cos(-0.05);
		old_plane_x = all->player.plane_x;
		all->player.plane_x = all->player.plane_x * cos(-0.05) - all->player.plane_y * sin(-0.05);
		all->player.plane_y = old_plane_x * sin(-0.05) + all->player.plane_y * cos(-0.05);
	}

	if (all->move.r_arr)
	{
		double old_dir_x;
		double old_plane_x;

		old_dir_x = all->player.p_dir_x;
		all->player.p_dir_x = all->player.p_dir_x * cos(0.05) - all->player.p_dir_y * sin(0.05);
		all->player.p_dir_y = old_dir_x * sin(0.05) + all->player.p_dir_y * cos(0.05);
		old_plane_x = all->player.plane_x;
		all->player.plane_x = all->player.plane_x * cos(0.05) - all->player.plane_y * sin(0.05);
		all->player.plane_y = old_plane_x * sin(0.05) + all->player.plane_y * cos(0.05);
	}
}

static	int		ft_key_press(int key, t_all *all)
{
	if (key == 13)
		all->move.w = 1;
	if (key == 1)
		all->move.s = 1;
	if (key == 0)
		all->move.a = 1;
	if (key == 2)
		all->move.d = 1;
	if (key == 123)
		all->move.l_arr = 1;
	if (key == 124)
		all->move.r_arr = 1;
	if (key == 53)
	{
		mlx_destroy_window(all->window.mlx, all->window.win);
		exit(0);
	}
	return (0);
}

static	int		ft_key_release(int key, t_all *all)
{
	if (key == 13)
		all->move.w = 0;
	if (key == 1)
		all->move.s = 0;
	if (key == 0)
		all->move.a = 0;
	if (key == 2)
		all->move.d = 0;
	if (key == 123)
		all->move.l_arr = 0;
	if (key == 124)
		all->move.r_arr = 0;
	if (key == 53)
		all->move.esc = 0;
	return (0);
}

static	int		ft_key_controls(t_all *all)
{
	mlx_destroy_image(all->window.mlx, all->image.img);
	if (all->move.w || all->move.s)
		ft_move_w_s(all);
	if (all->move.a || all->move.d)
		ft_move_a_d(all);
	if (all->move.l_arr || all->move.r_arr)
		ft_turn_l_r(all);
	ft_drow_map(all);
	return (0);
}

void	ft_key_press_handler(t_all *all)
{
	all->move.w = 0;
	all->move.s = 0;
	all->move.a = 0;
	all->move.d = 0;
	all->move.l_arr = 0;
	all->move.r_arr = 0;
	all->move.esc = 0;
	mlx_hook(all->window.win, 2, (1L << 0), ft_key_press, all);
	mlx_hook(all->window.win, 3, 1L << 1, ft_key_release, all);
	mlx_loop_hook(all->window.mlx, ft_key_controls, all);
}