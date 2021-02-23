/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:56:29 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/23 15:09:35 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int			ft_y_len(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

static int	support_1(int *y, int *x, char **map, int temp)
{
	while (*y >= 0)
	{
		if (map[*y][*x] == '1')
			break ;
		if (map[*y][*x] == ' ')
			return (1);
		*y = *y - 1;
	}
	while (*x < (int)ft_strlen(map[temp]))
	{
		if (map[*y][*x] == '1')
			break ;
		if (map[temp][*x] == ' ')
			return (1);
		*x = *x + 1;
	}
	while (*x >= 0)
	{
		if (map[*y][*x] == '1')
			break ;
		if (map[temp][*x] == ' ')
			return (1);
		*x = *x - 1;
	}
	return (0);
}

int			ft_map_is_0(char **map, int y, int x, int *check)
{
	int	temp;

	temp = y;
	if (map[y][x] != '0')
		return (0);
	*check = (*check | 2);
	if (y == 0 || x == 0)
		return (1);
	while (y < ft_y_len(map))
	{
		if (map[y][x] == '1')
			break ;
		if (map[y++][x] == ' ')
			return (1);
	}
	y = temp;
	if (support_1(&y, &x, map, temp))
		return (1);
	return (0);
}

int			ft_map_is_2(char **map, int y, int x)
{
	int i;

	if ((i = 0) == 0 && map[y][x] != '2')
		return (0);
	while (map[i] != NULL)
		i++;
	if (y == 0 || x == 0 || x == (int)ft_strlen(map[y]) - 1 || y == i - 1)
		return (1);
	if ((int)ft_strlen(map[y + 1]) - 1 < x ||
			(int)ft_strlen(map[y - 1]) - 1 < x)
		return (1);
	if (map[y + 1][x] == ' ')
		return (1);
	if (map[y][x + 1] == ' ')
		return (1);
	if (map[y - 1][x] == ' ')
		return (1);
	if (map[y][x - 1] == ' ')
		return (1);
	return (0);
}

int			ft_map_is_o(char **map, int y, int x, int *check)
{
	if (map[y][x] != 'N' && map[y][x] != 'S' &&
			map[y][x] != 'W' && map[y][x] != 'E')
		return (0);
	if ((*check | 4) == *check)
		return (1);
	*check = (*check | 4);
	if (y > 0)
		if (map[y - 1][x] == '0')
			return (0);
	if (y < ft_y_len(map))
		if (map[y + 1][x] == '0')
			return (0);
	if (x > 0)
		if (map[y][x - 1] == '0')
			return (0);
	if (x < (int)ft_strlen(map[y]))
		if (map[y][x + 1] == '0')
			return (0);
	return (1);
}
