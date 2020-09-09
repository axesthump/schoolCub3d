/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:09:12 by casubmar          #+#    #+#             */
/*   Updated: 2020/08/07 17:08:57 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

typedef struct	s_fd
{
	int			fd;
	char		*str;
	char		*buff;
	int			i;
	int			end_of_read;
}				t_fd;

typedef struct	s_gnl
{
	t_fd		*fds;
	int			fds_size;
	int			last_el;
	int			count_open_fd;
}				t_gnl;

t_fd			*ft_bin_search(t_fd *fds, int start, int end, int id);
int				get_next_line(int fd, char **line);
int				ft_push_fd(t_gnl *gnl, int fd);
char			*ft_strdup_gnl(const char *str, int i);
#endif
