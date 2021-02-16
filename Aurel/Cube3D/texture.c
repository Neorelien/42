/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 15:44:33 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/13 18:46:55 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int				ft_pos_in_wall(t_data *mlx, int i)
{
	int	result;
	int count;

	count = 1;
	if (mlx->cardinal_point == 'N')
		while (mlx->data[i - count + mlx->x] != mlx->rgb_wall &&
				mlx->data[i - count] != mlx->rgb_floor)
			count++;
	if (mlx->cardinal_point == 'S')
		while (mlx->data[i + count - mlx->x] != mlx->rgb_wall &&
				mlx->data[i + count] != mlx->rgb_floor)
			count++;
	if (mlx->cardinal_point == 'W')
		while (mlx->data[i + (count * mlx->x) + 1] != mlx->rgb_wall &&
				mlx->data[i + (count * mlx->x)] != mlx->rgb_floor)
			count++;
	if (mlx->cardinal_point == 'E')
		while (mlx->data[i - (count * mlx->x) - 1] != mlx->rgb_wall &&
				mlx->data[i - (count * mlx->x)] != mlx->rgb_floor)
			count++;
	result = count % mlx->ratio_map;
	if (result == 0)
		result = mlx->ratio_map - 1;
	result -= 1;
	return (result);
}

int				ft_change_pos(int ex_i, int i, int pos_in_wall, t_data *mlx)
{
	int diff;

	if (mlx->cardinal_point == 'N' || mlx->cardinal_point == 'S')
		diff = ft_variance(ex_i, i);
	else
		diff = ft_variance(ft_y(ex_i, mlx), ft_y(i, mlx));
	while (diff-- > 0)
	{
		if (pos_in_wall == 0)
			pos_in_wall = mlx->ratio_map - 1;
		else
			pos_in_wall--;
	}
	return (pos_in_wall);
}

static void		sup1(t_data *mlx, int *cor, float pos_in_wall,
		long double county)
{
	if (mlx->cardinal_point == 'N')
	{
		cor[0] = (pos_in_wall / mlx->ratio_map) * mlx->wall_one_size[0];
		cor[1] = (county - cor[3]) / (cor[4] - cor[3]) * mlx->wall_one_size[1];
		cor[2] = mlx->xpm_data[0][cor[1] * mlx->wall_one_size[0] + cor[0]];
	}
	if (mlx->cardinal_point == 'S')
	{
		cor[0] = (pos_in_wall / mlx->ratio_map) * mlx->wall_two_size[0];
		cor[1] = (county - cor[3]) / (cor[4] - cor[3]) * mlx->wall_two_size[1];
		cor[2] = mlx->xpm_data[1][cor[1] * mlx->wall_two_size[0] + cor[0]];
	}
	if (mlx->cardinal_point == 'E')
	{
		cor[0] = (pos_in_wall / mlx->ratio_map) * mlx->wall_three_size[0];
		cor[1] = (county - cor[3]) / (cor[4] - cor[3]) *
			mlx->wall_three_size[1];
		cor[2] = mlx->xpm_data[2][cor[1] * mlx->wall_three_size[0] + cor[0]];
	}
	if (mlx->cardinal_point == 'W')
	{
		cor[0] = (pos_in_wall / mlx->ratio_map) * mlx->wall_four_size[0];
		cor[1] = (county - cor[3]) / (cor[4] - cor[3]) * mlx->wall_four_size[1];
		cor[2] = mlx->xpm_data[3][cor[1] * mlx->wall_four_size[0] + cor[0]];
	}
}

int				ft_put_texture(t_data *mlx, int i, long double county, int *y)
{
	static float	pos_in_wall = -1.00000;
	static int		ex_i;
	int				cor[5];

	cor[3] = y[0];
	cor[4] = y[1];
	if (pos_in_wall == -1)
		mlx->ex_card_point = mlx->cardinal_point;
	if (mlx->ex_card_point != mlx->cardinal_point)
		pos_in_wall = -1;
	if (pos_in_wall == -1 || i <= (ex_i - (mlx->x * mlx->ratio_map)) ||
			i >= ex_i + (mlx->x * mlx->ratio_map))
		pos_in_wall = ft_pos_in_wall(mlx, i);
	else if (i != ex_i)
		pos_in_wall = ft_change_pos(ex_i, i, pos_in_wall, mlx);
	sup1(mlx, cor, pos_in_wall, county);
	ex_i = i;
	mlx->ex_card_point = mlx->cardinal_point;
	return (cor[2]);
}

int				ft_init_xmp(t_data *mlx)
{
	if ((mlx->wone_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->wall_one_path, &mlx->wall_one_size[0],
					&mlx->wall_one_size[1])) == NULL)
		return (1);
	if ((mlx->wtwo_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->wall_two_path, &mlx->wall_two_size[0],
					&mlx->wall_two_size[1])) == NULL)
		return (1);
	if ((mlx->wthree_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->wall_three_path, &mlx->wall_three_size[0],
					&mlx->wall_three_size[1])) == NULL)
		return (1);
	if ((mlx->wfour_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->wall_four_path, &mlx->wall_four_size[0],
					&mlx->wall_four_size[1])) == NULL)
		return (1);
	if ((mlx->sprite_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr,
					mlx->sprite_path, &mlx->sprite_size[0],
					&mlx->sprite_size[1])) == NULL)
		return (1);
	if (ft_init_data_xpm(mlx))
		return (1);
	return (0);
}
