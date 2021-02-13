/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   td_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 16:04:38 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/13 18:43:22 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

float		ft_floatcomp(float a, float b)
{
	float count;

	count = 0;
	if (a > b)
		return (a - b);
	else if (b > a)
		return (b - a);
	return (0);
}

int			ft_variance(int a, int b)
{
	int count;

	count = 0;
	if (a > b)
		while (a - count > b)
			count++;
	else
		while (b - count > a)
			count++;
	return (count);
}

int			ft_3d_win_init(t_data *mlx)
{
	int b_p;
	int end;
	int s_l;

	if ((mlx->td_img_ptr =
				mlx_new_image(mlx->mlx_ptr, mlx->x_td, mlx->y_td)) == NULL)
		return (1);
	if ((mlx->td_data = (int*)mlx_get_data_addr(mlx->td_img_ptr,
					&b_p, &s_l, &end)) == NULL)
		return (1);
	if ((mlx->td_win_ptr = mlx_new_window(mlx->mlx_ptr,
					mlx->x_td, mlx->y_td, "Cube3D")) == NULL)
		return (1);
	return (0);
}

static void	supprot(int *x, int county, t_data *mlx, int *y)
{
	if (county < y[0])
		mlx->td_data[pos_td(mlx, x[0], county)] = mlx->rgb_sky;
	else
		mlx->td_data[pos_td(mlx, x[0], county)] = mlx->rgb_floor;
}

void		ft_put_colomn(int *x, int *y, t_data *mlx, int i)
{
	long double	county;

	while (x[0]-- > x[1] && (county = -1.00000) == -1)
	{
		while (++county < mlx->y_td)
		{
			if (county >= y[0] && county < y[1])
			{
				if (mlx->cardinal_point == 'N')
					mlx->td_data[pos_td(mlx, x[0], county)] =
						ft_put_texture(mlx, i, county, y);
				if (mlx->cardinal_point == 'S')
					mlx->td_data[pos_td(mlx, x[0], county)] =
						ft_put_texture(mlx, i, county, y);
				if (mlx->cardinal_point == 'W')
					mlx->td_data[pos_td(mlx, x[0], county)] =
						ft_put_texture(mlx, i, county, y);
				if (mlx->cardinal_point == 'E')
					mlx->td_data[pos_td(mlx, x[0], county)] =
						ft_put_texture(mlx, i, county, y);
			}
			else
				supprot(x, county, mlx, y);
		}
	}
}
