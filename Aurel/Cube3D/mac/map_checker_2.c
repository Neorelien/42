/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:09:05 by Aurelien          #+#    #+#             */
/*   Updated: 2021/03/03 19:28:51 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

static int	support_1(int *count, int x, int *y, char **map)
{
	if (*y == 0)
		if (x >= (int)ft_strlen(map[*y + 1]))
			return (1);
	if (*y >= (int)ft_y_len(map))
		if (x >= (int)ft_strlen(map[*y - 1]))
			return (1);
	if (map[*y][x] == '1')
	{
		*count = *count + 1;
		return (1);
	}
	if (ft_nofloor(map[*y][x]))
		return (1);
	if (0 < *y && *y < ft_y_len(map))
	{
		if (x >= (int)ft_strlen(map[*y + 1]))
			return (1);
		if (x >= (int)ft_strlen(map[*y - 1]))
			return (1);
	}
	*y = *y - 1;
	return (0);
}

static void	support_2(int *count, int *cr, char **map, int *tp)
{
	cr[1] = tp[1];
	while (cr[0] < (int)ft_strlen(map[cr[1]]) && *count < 3)
	{
		if (map[cr[1]][cr[0] + 1] == '1' && (*count = *count + 1))
			break ;
		if (ft_nofloor(map[cr[1]][cr[0]++ + 1]))
			break ;
	}
	cr[0] = tp[0];
	while (cr[0] >= 0 && *count < 4)
	{
		if (map[cr[1]][cr[0] - 1] == '1' && (*count = *count + 1))
			break ;
		if (ft_nofloor(map[cr[1]][cr[0]-- - 1]))
			break ;
	}
	while ((cr[0] = tp[0]) && cr[0] < (int)ft_strlen(map[cr[1]]) && cr[1] >= 0)
	{
		if (map[cr[1]][cr[0]] == '1' && (*count = *count + 1))
			break ;
		if (ft_nofloor(map[cr[1]--][cr[0]++]))
			break ;
	}
	cr[1] = tp[1];
	cr[0] = tp[0];
}

static void	support_3(int *count, int *coor, char **map, int *temp)
{
	while (coor[1] < (int)ft_y_len(map) && coor[0]
			< (int)ft_strlen(map[coor[1]]))
	{
		if (map[coor[1]][coor[0]] == '1')
		{
			*count = *count + 1;
			break ;
		}
		if (ft_nofloor(map[coor[1]++][coor[0]++]))
			break ;
	}
	coor[1] = temp[1];
	coor[0] = temp[0];
	while (coor[0] >= 0 && coor[1] >= 0)
	{
		if (map[coor[1]][coor[0]] == '1')
		{
			*count = *count + 1;
			break ;
		}
		if (ft_nofloor(map[coor[1]--][coor[0]--]))
			break ;
	}
	coor[1] = temp[1];
	coor[0] = temp[0];
}

static int	support_4(int *count, int *coor, char **map)
{
	while (coor[1] < ft_y_len(map) && coor[0] >= 0)
	{
		if (map[coor[1]][coor[0]] == '1')
		{
			*count = *count + 1;
			break ;
		}
		if (ft_nofloor(map[coor[1]++][coor[0]--]))
			break ;
	}
	if (*count == 8)
		return (1);
	return (0);
}

int			ft_map_is_close(char **map, int *coor)
{
	int count;
	int	temp[2];

	temp[0] = coor[0];
	count = 0;
	if (ft_supsup(temp, coor, map) != -1)
		return (ft_supsup(temp, coor, map));
	while (coor[1] < ft_y_len(map) && count < 1)
	{
		if (coor[0] > 0 && coor[0] >= (int)ft_strlen(map[temp[1]]) - 1)
			return (1);
		if (map[coor[1]][coor[0]] == '1')
			count++;
		if (ft_nofloor(map[coor[1]++][coor[0]]))
			return (1);
	}
	coor[1] = temp[1];
	while (coor[1] >= 0 && count < 2)
		if (support_1(&count, coor[0], &coor[1], map))
			break ;
	support_2(&count, coor, map, temp);
	support_3(&count, coor, map, temp);
	if (support_4(&count, coor, map))
		return (0);
	return (1);
}
