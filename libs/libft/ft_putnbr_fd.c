/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 12:58:31 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/05 16:32:44 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_fd_l(long num, int fd)
{
	if (num >= 10)
		ft_putnbr_fd_l(num / 10, fd);
	ft_putchar_fd((num % 10) + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	ft_putnbr_fd_l(num, fd);
}
