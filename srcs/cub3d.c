/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:37:52 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 20:20:31 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_create_window(t_all *all)
{
	all->window.mlx = mlx_init();
	all->window.win = mlx_new_window(all->window.mlx, all->window.screen_w,
					all->window.screen_h, "cub3d");
}

int				main(int argc, char **argv)
{
	int		i;
	int		fd;
	t_all	all;
	t_list	*list;
	int		err;

	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) == -1)
		return (1);
	if ((err = ft_get_map_and_player(&all, fd)) < 0)
		return (ft_error_handler(&all, list, err));
	ft_create_window(&all);
	if (ft_init_textures(&all))
		return (0);
	all.raycast.buffer = malloc(sizeof(double) * (all.window.screen_w));
	ft_drow_map(&all);
	ft_key_press_handler(&all);
	mlx_loop(all.window.mlx);
	return (0);
}
