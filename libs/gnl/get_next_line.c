/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:00:01 by casubmar          #+#    #+#             */
/*   Updated: 2020/08/07 16:55:40 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		ft_init(t_gnl **gnl)
{
	if (!(*gnl = (t_gnl *)malloc(sizeof(t_gnl))))
		return (-1);
	(*gnl)->fds = NULL;
	if (!((*gnl)->fds = (t_fd *)malloc(sizeof(t_fd) * 2)))
		return (-1);
	(*gnl)->fds[0].fd = 0;
	(*gnl)->fds[1].fd = 0;
	(*gnl)->last_el = 0;
	(*gnl)->fds_size = 2;
	(*gnl)->count_open_fd = 0;
	return (1);
}

static	char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (s1[i])
		++i;
	while (s2[j])
		++j;
	if (!(res = (char *)malloc(i + j + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

static	int		ft_read_remainder(t_fd *fd, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while (fd->str[i] && fd->str[i] != '\n')
		++i;
	if (fd->str[i] == '\n')
	{
		fd->str[i] = '\0';
		free(*line);
		*line = ft_strdup_gnl(fd->str, 0);
		temp = fd->str;
		fd->str = ft_strdup_gnl(fd->str, i + 1);
		free(temp);
		return (1);
	}
	else
	{
		free(*line);
		*line = ft_strdup_gnl(fd->str, 0);
		free(fd->str);
		fd->str = ft_strdup_gnl("", 0);
		return (0);
	}
}

static	int		ft_read(t_fd *fd, char **line, t_gnl *gnl)
{
	int res;

	if (fd->str && ((res = ft_read_remainder(fd, line)) == 1 || res == -1))
		return (res);
	while ((fd->end_of_read = read(fd->fd, fd->buff, BUFFER_SIZE)))
	{
		if (fd->end_of_read < 0)
			return (-1);
		fd->buff[fd->end_of_read] = '\0';
		fd->i = -1;
		while (++(fd->i) < fd->end_of_read)
			if (fd->buff[fd->i] == '\n')
			{
				fd->buff[fd->i] = '\0';
				*line = ft_strjoin_gnl(*line, fd->buff);
				free(fd->str);
				fd->str = ft_strdup_gnl(fd->buff, fd->i + 1);
				return (1);
			}
		*line = ft_strjoin_gnl(*line, fd->buff);
	}
	free(fd->str);
	free(fd->buff);
	gnl->count_open_fd -= 1;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_fd			*fd_f;
	int				res;

	if (!line)
		return (-1);
	*line = ft_strdup_gnl("", 0);
	if (!gnl)
		if (ft_init(&gnl) == -1)
			return (-1);
	if (gnl->last_el == 0 || !ft_bin_search(gnl->fds, 0, gnl->last_el - 1, fd))
		if ((ft_push_fd(gnl, fd)) == -1)
			return (-1);
	fd_f = ft_bin_search(gnl->fds, 0, gnl->last_el, fd);
	res = ft_read(fd_f, line, gnl);
	if (gnl->count_open_fd <= 0)
	{
		free(gnl->fds);
		free(gnl);
		gnl = NULL;
	}
	return (res);
}
