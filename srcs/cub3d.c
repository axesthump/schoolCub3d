/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:37:52 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 21:01:04 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_create_window(t_all *all)
{
	all->window.mlx = mlx_init();
	all->window.win = mlx_new_window(all->window.mlx, all->window.screen_w,
					all->window.screen_h, "cub3d");
}

static	int		ft_do_screen(t_all *all, t_list *list, char **argv)
{
	if (ft_strncmp(argv[2], "--save", 10) != 0)
			return (ft_error_handler(all, list, 9));
	return (ft_make_screen(all));
}

static	int		ft_val_format(char *map)
{
	while (*map != '.' && *map)
		++map;
	if (!*map)
		return (-1);
	if (ft_strncmp(map, ".cub", 5) != 0)
		return (-1);
	return (1);
}

int				main(int argc, char **argv)
{
	int		fd;
	t_all	all;
	int		err;

	all.list = NULL;
	if (argc > 3 || argc == 1 || (fd = open(argv[1], O_RDONLY)) == -1)
		return (ft_error_handler(&all, all.list, 8));
	if (ft_val_format(argv[1]) < 0)
		return (ft_error_handler(&all, all.list, 10));
	if ((err = ft_get_map_and_player(&all, fd, all.list)) < 0)
		return (ft_error_handler(&all, all.list, err));
	ft_create_window(&all);
	if (ft_init_textures(&all))
		return (ft_error_handler(&all, all.list, 7));
	all.raycast.buffer = malloc(sizeof(double) * (all.window.screen_w));
	if (argc == 3)
		return (ft_do_screen(&all, all.list, argv));
	ft_key_press_handler(&all);
	ft_drow_map(&all);
	mlx_loop(all.window.mlx);
	return (0);
}
