/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 20:44:10 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/07 21:12:33 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int		ft_all_ruls(t_all *all)
{
	if (all->validate.c == 1 && all->validate.ea == 1 && all->validate.f == 1
	&& all->validate.no == 1 && all->validate.r == 1 && all->validate.s == 1
	&& all->validate.s == 1 && all->validate.so == 1 && all->validate.we == 1)
		return (1);
	return (0);
}

static	int		ft_check_row(char *row, t_all *all)
{
	int err;
	int	change;

	change = 0;
	if (row[0] == '\0')
		return (0);
	else
	{
		if (row[0] == 'R' && (change = 1))
			if ((ft_get_screen(all, row)) < 0)
				return (-2);
		if ((err = ft_check_nswe(all, row, &change)) < 0)
			return (err);
		if (row[0] == 'F' && (change = 1))
			if ((err = ft_get_f(all, row + 1)) < 0)
				return (err);
		if (row[0] == 'C' && (change = 1))
			if ((err = ft_get_c(all, row + 1)) < 0)
				return (err);
		if ((ft_is_start_map(row) && ft_all_ruls(all)) || change)
			return (0);
		else
			return (-1);
		return (0);
	}
}

static	int		ft_check_first_row(char *str)
{
	if (str[0] == ' ' || str[0] == '\n' || str[0] == '\t' || str[0] == '\0')
		return (-1);
	return (0);
}

static	void	ft_init_validate(t_all *all)
{
	all->validate.c = 0;
	all->validate.ea = 0;
	all->validate.f = 0;
	all->validate.no = 0;
	all->validate.r = 0;
	all->validate.s = 0;
	all->validate.so = 0;
	all->validate.we = 0;
}

int				ft_validate(t_all *all, t_list **list)
{
	t_list	*head;
	char	*row;
	int		err;

	head = *list;
	ft_init_validate(all);
	if ((ft_check_first_row(head->content)) == -1)
		return (-1);
	while (head)
	{
		if ((err = ft_check_row(head->content, all)) < 0)
			return (err);
		head = head->next;
	}
	return (0);
}
