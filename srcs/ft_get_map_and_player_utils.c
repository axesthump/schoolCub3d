/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_and_player_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 17:52:56 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 21:26:06 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_list			*ft_get_map(t_list *list)
{
	char	*content;
	t_list	*tmp;

	content = list->content;
	while (!ft_is_start_map(content) || content[0] == '\0')
	{
		tmp = list->next;
		content = tmp->content;
		free(list->content);
		free(list);
		list = tmp;
	}
	return (list);
}