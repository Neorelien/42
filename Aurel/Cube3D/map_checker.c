/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:56:29 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/16 03:09:05 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"

int	ft_y_len(char **str)
{
	int i;
	
	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
int	ft_map_is_0(char **map, int y, int x, int *check)
{
	if (map[y][x] != '0')
		return (0);
	*check = * check + 1;
	if (y == 0 || x == 0)
		return (1);
	if (y == ft_y_len(map) || x == ft_strlen(map[y]))
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

int	ft_map_is_1(char **map, int y, int x, int *check)
{
	int count;
	int	temp;

	temp = y;
	count = 0;
	if (map[y][x] != '0')
		return (0);
	printf("%d\n", ft_y_len(map));
//	while (y < ft_y_len(map) || map[y][x] != '1')
//		if (map[y++][x] == '1')
//			count++;
/*	while (y >= 0 || map[y][x] != 1)
		if (map[y--][x] == '1')
			count++;
	while (x < ft_strlen(map[x]) || map[temp][x] != '1')
		if (map[temp][x++] == '1')
			count++;*/
	while (x >= 0 || map[temp][x] != '1')
		if (map[temp][x--] == '1')
			count++;
	if (count == 4)
		return (0);
	return (1);
}

int	ft_map_is_2(char **map, int y, int x, int *check)
{
	if (map[y][x] != '2')
		return (0);
	if (y == 0 || x == 0)
		return (1);
	if (map[y + 1][x] ==' ')
		return (1);
	if (map[y][x + 1] ==' ')
		return (1);
	if (map[y - 1][x] ==' ')
		return (1);
	if (map[y][x - 1] ==' ')
		return (1);
	return (0);
}

int	ft_map_is_O(char **map, int y, int x, int *check)
{
	if (map[y][x] != 'N' || map[y][x] != 'S' ||
			map[y][x] != 'W' || map[y][x] != 'E') 
		return (0);
	*check = *check + 1;
	return (0);
}
