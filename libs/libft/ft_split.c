/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:46:54 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/06 16:44:35 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlen(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

static int		ft_getcount(const char *s, char c)
{
	size_t	i;
	size_t	len;
	int		flag;

	len = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] == c && s[i])
		{
			++i;
			flag = 1;
		}
		else
		{
			if (flag)
				++len;
			flag = 0;
			++i;
		}
	}
	return (len);
}

static char		*ft_update(char *s, char c)
{
	while (*s == c && *s)
		++s;
	return (s);
}

static	void	ft_clear(char **res)
{
	char *temp;

	temp = *res;
	while (temp)
	{
		free(temp);
		++temp;
	}
	free(res);
}

char			**ft_split(char const *s, char c)
{
	char	*modern_s;
	size_t	k;
	size_t	len;
	char	**res;

	if (!s)
		return (NULL);
	k = 0;
	modern_s = (char *)s;
	len = ft_getcount(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	while (k < len)
	{
		modern_s = ft_update(modern_s, c);
		if (!(res[k] = (char *)malloc(ft_getlen(modern_s, c) + 1)))
		{
			ft_clear(res);
			return (NULL);
		}
		ft_strlcpy(res[k++], modern_s, ft_getlen(modern_s, c) + 1);
		modern_s += ft_getlen(modern_s, c);
	}
	res[k] = NULL;
	return (res);
}
