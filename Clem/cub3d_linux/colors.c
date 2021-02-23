/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 23:52:27 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 18:08:28 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_make_color_cf_second(char *str, t_color *color, int i)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
	while (str[i])
	{
		color->tot = 0;
		while (str[i] == ' ' && str[i])
			i++;
		if (!ft_isnum(str[i]))
			return (0);
		while (ft_isnum(str[i]) && str[i])
			color->tot = color->tot * 10 + str[i++] - 48;
		if (color->r == -1)
			color->r = color->tot;
		else if (color->g == -1)
			color->g = color->tot;
		else if (color->b == -1)
			color->b = color->tot;
		if (str[i] != ',' || !str[i])
			return (i);
		else
			i++;
	}
	return (i);
}

void	ft_make_color_cf(char *str, t_mlx *mlx)
{
	int		i;
	t_color color;

	i = 1;
	i = ft_make_color_cf_second(str, &color, i);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255 || mlx->error || str[i] != 0)
	{
		mlx->error = ERROR_IN_PARS;
		return ;
	}
	if (str[0] == 'F')
	{
		if (mlx->color_f != -1)
			mlx->error = ERROR_IN_PARS;
		mlx->color_f = color.r * 256 * 256 + color.g * 256 + color.b;
	}
	if (str[0] == 'C')
	{
		if (mlx->color_c != -1)
			mlx->error = ERROR_IN_PARS;
		mlx->color_c = color.r * 256 * 256 + color.g * 256 + color.b;
	}
}
