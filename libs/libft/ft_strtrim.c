/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 20:43:16 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/05 11:16:02 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_instr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		++i;
	}
	return (0);
}

static int		ft_trimstart(const char *str, const char *set)
{
	int i;

	i = 0;
	while (str[i] && ft_instr(set, str[i]))
		++i;
	return (i);
}

static int		ft_trimend(const char *str, const char *set)
{
	int i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_instr(set, str[i]))
		--i;
	return (i);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = ft_trimstart(s1, set);
	end = ft_trimend(s1, set);
	if (start > end)
	{
		res = (char *)malloc(1);
		res[0] = '\0';
		return (res);
	}
	if (!(res = (char *)malloc(((end - start) + 1) + 1)))
		return (NULL);
	while (start <= end)
		res[i++] = s1[start++];
	res[i] = '\0';
	return (res);
}
