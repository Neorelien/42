/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:56:29 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/17 19:34:19 by Aurelien         ###   ########.fr       */
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
	int count;
	int	temp;

	temp = y;
	count = 0;
	if (map[y][x] != '0')
		return (0);
	*check = (*check | 2);
	if (y == 0 || x == 0)
		return (1);
	while (y < ft_y_len(map) && count < 1)
		if (map[y++][x] == ' ')
			return (1);
	y = temp;
	while (y >= 0 && count < 2)
		if (map[y--][x] == ' ')
			return (1);
	while (x < ft_strlen(map[temp]) && count < 3)
		if (map[temp][x++] == ' ')
			return (1);
	while (x >= 0 && count < 4)
		if (map[temp][x--] == ' ')
			return (1);
	return (0);
}	

int	ft_map_is_close(char **map, int y, int x, int *check)
{
	int count;
	int	tempy;
	int tempx;

	tempy = y;
	tempx = x;
	count = 0;
	if (map[y][x] != '0')
		return (0);
	while (y < ft_y_len(map) && count < 1)
		if (map[y++][x] == '1')
			count++;
	y = tempy;
	while (y >= 0 && count < 2)
	{
		if (y == 0)
			if (x >= ft_strlen(map[y + 1]))
				break ;
		if (y == ft_y_len(map))
			if (x >= ft_strlen(map[y - 1]))
				break ;
		if (0 < y && y < ft_y_len(map))
		{
			if (x >= ft_strlen(map[y + 1]))
				break ;
			if (x >= ft_strlen(map[y - 1]))
				break ;
		}
		if (map[y--][x] == '1')
		{
			count++;
			break;
		}
	}
	y = tempy;
	while (x < ft_strlen(map[y]) && count < 3)
		if (map[y][x++ + 1] == '1')
		{
			count++;
			break ;
		}
	x = tempx;
	while (x >= 0 && count < 4)
		if (map[y][x-- - 1] == '1')
		{
			count++;
			break ;
		}
	x = tempx;
	while (x < ft_strlen(map[y]) && y >= 0)
		if (map[y-- - 1][x++ + 1] == '1')
			{
				count++;
				break ;
			}
	y = tempy;
	x = tempx;
	while (x < ft_strlen(map[y]) && y < ft_y_len(map))
	{
		printf("valeur de x %d, y %d = \n", x, y);
		if (map[y++ + 1][x++ + 1] == '1')
			{
				count++;
				break ;
			}
	}
	if (count == 6)
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
	if (x < ft_strlen(map[y]))
		if (map[y][x + 1] == '0')
			return (0);
	return (1);
}
