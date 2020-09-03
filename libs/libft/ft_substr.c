/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:33:12 by casubmar          #+#    #+#             */
/*   Updated: 2020/05/07 09:06:49 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;
	size_t	len_s;

	if (!s || start > ft_strlen(s) - 1)
		return (NULL);
	len_s = ft_strlen(s + start);
	if (len_s < len)
		len = len_s;
	if (!(res = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		++i;
	}
	res[i] = '\0';
	return (res);
}
