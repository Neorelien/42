/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:14:32 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:14:34 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	find_info(char *tex_path, t_textures *textures)
{
	textures->path = tex_path;
	textures->malloc = 1;
}

int		take_info(char **info, t_mlx *mlx, int count)
{
	if (info[count][0] == 'N' && info[count][0 + 1] == 'O')
		find_info(make_textures_path(*info + 2, mlx), &mlx->tex_n);
	else if (info[count][0] == 'S' && info[count][0 + 1] == 'O')
		find_info(make_textures_path(*info + 2, mlx), &mlx->tex_s);
	else if (info[count][0] == 'W' && info[count][0 + 1] == 'E')
		find_info(make_textures_path(*info + 2, mlx), &mlx->tex_w);
	else if (info[count][0] == 'E' && info[count][0 + 1] == 'A')
		find_info(make_textures_path(*info + 2, mlx), &mlx->tex_e);
	else if (info[count][0] == 'S')
		find_info(make_textures_path(*info + 2, mlx), &mlx->tex_sprite);
	else if (info[count][0] == 'F' || info[count][0] == 'C')
		ft_make_color_cf(info[count], mlx);
	if (info[count][0] && ft_ismaj(info[count][0]))
	{
		ft_double_pointer_free(info, count, 0);
		count = 0;
	}
	else if (info[count][0] == 0)
		free(info[count]);
	else
		count++;
	return (count);
}

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
	t_color	color;

	i = 1;
	i = ft_make_color_cf_second(str, &color, i);
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255
		|| color.b < 0 || color.b > 255 || mlx->error || str[i] != 0)
	{
		mlx->error = ERROR_COLORS;
		ft_error(mlx);
	}
	if (str[0] == 'F')
		mlx->floor_color = color.r * 256 * 256 + color.g * 256 + color.b;
	if (str[0] == 'C')
		mlx->ceil_color = color.r * 256 * 256 + color.g * 256 + color.b;
}
