/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:57:56 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 19:02:26 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_strncmp(const char *str, const char *str2, size_t n)
{
	size_t i;

	i = 0;
	while ((*str || *str2) && i < n)
	{
		if (*str != *str2)
			return ((unsigned char)*str - (unsigned char)*str2);
		++str;
		++str2;
		++i;
	}
	return (0);
}

char	*ft_strrchr(const char *str, int ch)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == (unsigned char)ch)
			return ((char *)(str + i));
		--i;
	}
	return (NULL);
}

static char		*ft_clean(char *s)
{
	while (*s && (*s == ' ' || *s == '\t' || *s == '\v' || *s == '\f'
	|| *s == '\r' || *s == '\n'))
		++s;
	if (!*s)
		return (0);
	else if (*s >= '0' && *s <= '9')
		return (s);
	else if ((*s == '-' || *s == '+') && (*(s + 1) >= '0' && *(s + 1) <= '9'))
		return (s);
	else
		return (0);
}

static	long	ft_getres(char *num, int last_index, int sign)
{
	long	result;
	int		mult;
	long	temp;

	mult = 1;
	result = 0;
	while (last_index >= 0)
	{
		temp = result;
		result += (num[last_index] - '0') * mult;
		mult *= 10;
		--last_index;
		if ((temp > result) && sign == 1)
			return (-1);
		else if ((temp > result) && sign == -1)
			return (0);
	}
	return (result * sign);
}

int				ft_atoi(const char *nptr)
{
	char	*clean_row;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	clean_row = ft_clean((char *)nptr);
	if (!clean_row)
		return (0);
	if (*clean_row == '-')
	{
		sign = -1;
		++clean_row;
	}
	else if (*clean_row == '+')
		++clean_row;
	while (ft_isdigit(clean_row[i]))
		++i;
	return (ft_getres(clean_row, i - 1, sign));
}
