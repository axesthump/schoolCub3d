/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 13:00:35 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 18:30:40 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static void		ft_quick_sort(t_fd *fds, int start, int end)
{
	int		mid;
	int		left;
	int		right;
	t_fd	temp;

	if (start > end)
		return ;
	mid = fds[(start + end) / 2].fd;
	left = start;
	right = end;
	while (left <= right)
	{
		while (fds[left].fd < mid)
			++left;
		while (fds[right].fd > mid)
			--right;
		if (left <= right)
		{
			temp = fds[left];
			fds[left++] = fds[right];
			fds[right--] = temp;
		}
	}
	ft_quick_sort(fds, start, right);
	ft_quick_sort(fds, left, end);
}

char			*ft_strdup_gnl(const char *str, int i)
{
	char	*res;
	int		len;
	int		temp;

	len = 0;
	temp = i;
	while (str[temp])
	{
		++temp;
		++len;
	}
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	len = 0;
	while (str[i])
	{
		res[len] = str[i];
		++i;
		++len;
	}
	res[len] = '\0';
	return (res);
}

static	void	*ft_elcpy(t_fd *dest, t_fd *src, size_t n)
{
	size_t i;

	if (!dest && !src)
		return (dest);
	i = 0;
	while (i < n)
	{
		dest[i].fd = src[i].fd;
		dest[i].str = src[i].str;
		dest[i].buff = src[i].buff;
		dest[i].end_of_read = src[i].end_of_read;
		++i;
	}
	return (dest);
}

int				ft_push_fd(t_gnl *gnl, int fd)
{
	t_fd	*temp;

	if (gnl->last_el + 1 >= gnl->fds_size)
	{
		if (!(temp = (t_fd *)malloc(sizeof(t_fd) * gnl->fds_size * 2)))
			return (0);
		ft_elcpy(temp, gnl->fds, gnl->last_el + 1);
		free(gnl->fds);
		gnl->fds = temp;
		gnl->fds_size *= 2;
	}
	gnl->count_open_fd += 1;
	gnl->fds[gnl->last_el].fd = fd;
	if (!(gnl->fds[gnl->last_el].buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	gnl->fds[gnl->last_el].i = -1;
	gnl->fds[gnl->last_el].str = NULL;
	gnl->fds[gnl->last_el].end_of_read = 0;
	ft_quick_sort(gnl->fds, 0, gnl->last_el);
	gnl->last_el += 1;
	return (1);
}

t_fd			*ft_bin_search(t_fd *fds, int start, int end, int id)
{
	if (start == 0 && end == 0)
	{
		if (fds[start].fd == id)
			return (fds + start);
		return (NULL);
	}
	else if (start + 1 == end)
	{
		if (fds[start].fd == id)
			return (fds + start);
		else if (fds[end].fd == id)
			return (fds + end);
		else
			return (NULL);
	}
	else if (fds[(start + end) / 2].fd > id)
		return (ft_bin_search(fds, start, (start + end) / 2, id));
	else
		return (ft_bin_search(fds, (start + end) / 2, end, id));
}
