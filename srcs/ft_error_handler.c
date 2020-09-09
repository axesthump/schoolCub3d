/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: casubmar <casubmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 13:54:08 by casubmar          #+#    #+#             */
/*   Updated: 2020/09/09 21:02:40 by casubmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	1 - Первая строка пустая (Конфиг начинается на пустую строку) 
	2 - Неверный параметр (пробел<-R || Не та буква)
	3 - Нет такого файла
	4 - Ошибка пола потолок
	5 - Ошибка малока
	6 - Хуевая карта
	7 - Кривые текстуры
	8 - Плохие аргументы
	9 - Не удалось сделать скрин
	10 - Плохой аргумент карты
*/

int		ft_error_handler(t_all *all, t_list *head, int err)
{
	if (abs(err) == 1)
		ft_putendl_fd("Error\nBad parametrs", 2);
	else if (abs(err) == 2)
		ft_putendl_fd("Error\nWrong parametrs", 2);
	else if (abs(err) == 3)
		ft_putendl_fd("Error\nBad fail", 2);
	else if (abs(err) == 4)
		ft_putendl_fd("Error\nBad f/c parametr", 2);
	else if (abs(err) == 5)
		ft_putendl_fd("Error\nmalloc wrong", 2);
	else if (abs(err) == 6)
		ft_putendl_fd("Error\nBad map", 2);
	else if (abs(err) == 7)
		ft_putendl_fd("Error\nBad texture", 2);
	else if (abs(err) == 8)
		ft_putendl_fd("Error\nBad args", 2);
	else if (abs(err) == 9)
		ft_putendl_fd("Error\nBad screen", 2);
	else if (abs(err) == 10)
		ft_putendl_fd("Error\nBad map arg", 2);
	printf("trash - %f", all->player.x);
	printf("%s\n", head->content);
	exit(1);
	return (1);
}