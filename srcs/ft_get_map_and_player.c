/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_and_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:44:26 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 20:37:38 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	ft_check_ew(t_all **all, char c, int i, int j)
{
	if (c == 'W')
	{
		(*all)->player.x = j + 0.5;
		(*all)->player.y = i + 0.5;
		(*all)->player.p_dir_x = -1;
		(*all)->player.p_dir_y = 0;
		(*all)->player.plane_x = 0;
		(*all)->player.plane_y = -tan(M_PI * ANGLE / 360);
	}
	else if (c == 'E')
	{
		(*all)->player.x = j + 0.5;
		(*all)->player.y = i + 0.5;
		(*all)->player.p_dir_x = 1;
		(*all)->player.p_dir_y = 0;
		(*all)->player.plane_x = 0;
		(*all)->player.plane_y = tan(M_PI * ANGLE / 360);
	}
}

static	void	ft_check_ns(t_all **all, char c, int i, int j)
{
	if (c == 'N')
	{
		(*all)->player.x = j + 0.5;
		(*all)->player.y = i + 0.5;
		(*all)->player.p_dir_x = 0;
		(*all)->player.p_dir_y = -1;
		(*all)->player.plane_x = tan(M_PI * ANGLE / 360);
		(*all)->player.plane_y = 0;
	}
	else if (c == 'S')
	{
		(*all)->player.x = j + 0.5;
		(*all)->player.y = i + 0.5;
		(*all)->player.p_dir_x = 0.0001;
		(*all)->player.p_dir_y = 1;
		(*all)->player.plane_x = -tan(M_PI * ANGLE / 360);
		(*all)->player.plane_y = 0.0001;
	}
}

static	void	ft_check_line(t_all **all, char *row, int i)
{
	int j;

	j = -1;
	while (row[++j])
	{
		ft_check_ns(all, row[j], i, j);
		ft_check_ew(all, row[j], i, j);
		if (row[j] == '2')
		{
			if (!(*all)->sprite.el)
				(*all)->sprite.el = ft_sprite_new(j + 0.5, i + 0.5);
			else
				ft_sprite_add_back(&((*all)->sprite.el),
					ft_sprite_new(j + 0.5, i + 0.5));
		}
	}
}

static	int		ft_get(t_all **all, t_list **list)
{
	int		i;
	t_list	*tmp;

	tmp = *list;
	if (((*all)->window.map =
		(char **)ft_calloc(sizeof(char *), ft_lstsize(*list) + 1)) == NULL)
		return (1);
	i = -1;
	(*all)->sprite.el = NULL;
	while (tmp)
	{
		(*all)->window.map[++i] = tmp->content;
		ft_check_line(all, (*all)->window.map[i], i);
		tmp = tmp->next;
	}
	(*all)->window.map[++i] = NULL;
	return (0);
}

int				ft_get_map_and_player(t_all *all, int fd)
{
	t_list	*list;
	char	*line;
	int		err;

	list = NULL;
	while (get_next_line(fd, &line) > 0)
		ft_lstadd_back(&list, ft_lstnew(line));
	ft_lstadd_back(&list, ft_lstnew(line));
	if ((err = ft_validate(all, &list)) < 0)
		return (err);
	if (ft_get(&all, &list))
		return (1);
	return (0);
}
