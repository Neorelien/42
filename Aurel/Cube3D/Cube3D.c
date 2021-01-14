/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:40 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/14 19:29:00 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"

char **ft_map_dup(char **map)
{
	int		x;
	int		y;
	char	**dup;

	y = 0;
	x = 0;
	while (map[x] != NULL)
		x++;
	dup = (char**)malloc(sizeof(char*) * x + 1);
	x = 0;
	while (map[x] != NULL)
	{
		while (map[x][y++] != '\0')
			dup[x] = (char*)malloc(sizeof(char) * y-- + 1);
		x++;
	}
	while (map[x] != NULL)
	{
		dup[x] = ft_strdup(map[x]);
		x++;
	}
	return (dup);
}

int	ft_check_map(char **map)
{
	return (0);	
}

int	ft_map_init(int argc, char **argv, t_data *mlx)
{
	int		fd;
	int		nxt_line;
	char	**temp;

	temp = NULL;
	if (argc != 1)
		return (1);
	if ((fd = open(argv[1], O_RDONLY) == -1))
		return (1);
	nxt_line = get_next_line(fd, mlx->map);
	while (nxt_line != -1)
	{
		temp = ft_map_dup(mlx->map);
	}
	if (ft_check_map(mlx->map))
		return (1);
	return (0);	
}

int main(int argc, char **argv)
{
	t_data	mlx;

	if (ft_map_init(argc, argv, &mlx))
		return (1);
	return (0);
}
