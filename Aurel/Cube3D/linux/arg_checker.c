/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 19:08:14 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/17 18:54:53 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int				ft_check_map(char **map)
{
	static int	x;
	static int	y;
	static int	check;
	int			coor[2];

	while (map[y])
	{
		while (map[y][x])
		{
			coor[0] = x;
			coor[1] = y;
			if (ft_map_is_0(map, y, x, &check) || ft_map_is_close(map, coor) ||
					ft_map_is_2(map, y, x) || ft_map_is_o(map, y, x, &check))
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	if (check == 6)
		return (0);
	return (1);
}

static int		check_saver(char **argv, t_data *mlx, int i)
{
	mlx->save_pic = 1;
	while (argv[1][i] != '.')
		if (argv[1][i++] == '\0')
			return (1);
	i++;
	if (argv[1][i++] != 'c')
		return (1);
	if (argv[1][i++] != 'u')
		return (1);
	if (argv[1][i] != 'b')
		return (1);
	i = 1;
	if (argv[2][i++] != '-')
		return (1);
	if (argv[2][i++] != 's')
		return (1);
	if (argv[2][i++] != 'a')
		return (1);
	if (argv[2][i++] != 'v')
		return (1);
	if (argv[2][i++] != 'e')
		return (1);
	if (argv[2][i++] != '\0')
		return (1);
	return (0);
}

static int		check_no_saver(char **argv, t_data *mlx, int i)
{
	mlx->save_pic = 0;
	i = 0;
	while (argv[1][i] != '.')
		if (argv[1][i++] == '\0')
			return (1);
	i++;
	if (argv[1][i++] != 'c')
		return (1);
	if (argv[1][i++] != 'u')
		return (1);
	if (argv[1][i] != 'b')
		return (1);
	return (0);
}

int				ft_check_argv(char **argv, int argc, t_data *mlx)
{
	int i;

	i = 0;
	if (argc > 3 || argc < 2)
		return (1);
	if (argv[1][0] == '-')
		return (1);
	if (argc == 3 && argv[2][i] == '-')
	{
		if (check_saver(argv, mlx, i))
			return (1);
	}
	else
	{
		if (check_no_saver(argv, mlx, i))
			return (1);
	}
	return (0);
}

void			maping_sup(int fd, char **line, t_data *mlx, int *i)
{
	get_next_line(fd, line);
	mlx->map[*i] = *line;
	if ((int)ft_strlen(*line) > mlx->x_dd)
		mlx->x_dd = ft_strlen(*line);
	*i = *i + 1;
}
