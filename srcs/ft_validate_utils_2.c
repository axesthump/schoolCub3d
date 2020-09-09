/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:51:54 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 21:29:09 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char			*ft_init_color(char *row, long *n)
{
	*n = ft_atoi(row);
	while (ft_isdigit(*row))
		++row;
	if (*row != ',')
		return (NULL);
	++row;
	return (row);
}

int				ft_check_last_symbol(char *row, int is_num)
{
	int i;

	i = -1;
	while (row[++i])
		;
	if (is_num)
	{
		if (!ft_isdigit(row[i - 1]))
			return (-1);
	}
	else
	{
		if (row[i - 1] == ' ' || row[i - 1] == '\t')
			return (-1);
	}
	return (0);
}

int				ft_get_we(t_all *all, char *row)
{
	int fd;

	if (ft_check_last_symbol(row, 0) == -1)
		return (-3);
	if (row[1] != 'E')
		return (-2);
	row += 2;
	while (*row == ' ')
		++row;
	if ((fd = open(row, O_RDONLY)) == -1)
		return (-3);
	all->texturs.we.filename = ft_strdup(row);
	all->validate.we += 1;
	close(fd);
	if (all->validate.we != 1)
		return (-1);
	return (0);
}

int				ft_get_ea(t_all *all, char *row)
{
	int fd;

	if (ft_check_last_symbol(row, 0) == -1)
		return (-3);
	if (row[1] != 'A')
		return (-2);
	row += 2;
	while (*row == ' ')
		++row;
	if ((fd = open(row, O_RDONLY)) == -1)
		return (-3);
	all->texturs.ea.filename = ft_strdup(row);
	all->validate.ea += 1;
	close(fd);
	if (all->validate.ea != 1)
		return (-1);
	return (0);
}

int				ft_get_no(t_all *all, char *row)
{
	int fd;

	if (ft_check_last_symbol(row, 0) == -1)
		return (-3);
	if (row[1] != 'O')
		return (-2);
	row += 2;
	while (*row == ' ')
		++row;
	if ((fd = open(row, O_RDONLY)) == -1)
		return (-3);
	all->texturs.no.filename = ft_strdup(row);
	all->validate.no += 1;
	close(fd);
	if (all->validate.no != 1)
		return (-1);
	return (0);
}
