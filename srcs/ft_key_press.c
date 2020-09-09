/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 17:17:25 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 19:36:43 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		ft_key_exit(t_all *all)
{
	exit(0);
	++all;
	return (0);
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

void			ft_key_press_handler(t_all *all)
{
	all->move.w = 0;
	all->move.s = 0;
	all->move.a = 0;
	all->move.d = 0;
	all->move.l_arr = 0;
	all->move.r_arr = 0;
	all->move.esc = 0;
	mlx_hook(all->window.win, 2, (1L << 0), ft_key_press, all);
	mlx_hook(all->window.win, 3, (1L << 1), ft_key_release, all);
	mlx_hook(all->window.win, 17, (1L << 17), ft_key_exit, all);
	mlx_loop_hook(all->window.mlx, ft_key_controls, all);
}
