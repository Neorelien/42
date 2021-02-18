/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:41:12 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/14 00:09:43 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int			ft_elem_floor_color(char **line, t_data *mlx)
{
	char	*newline;
	int		f_color[3];

	newline = ft_strtrim(*line, "F ");
	free(*line);
	*line = NULL;
	f_color[0] = -1;
	f_color[1] = -1;
	f_color[2] = -1;
	if (ft_split_int(f_color, newline))
	{
		free(newline);
		return (1);
	}
	free(newline);
	if (f_color[0] < 0 || f_color[1] < 0 || f_color[2] < 0)
		return (1);
	if (f_color[0] > 255 || f_color[1] > 255 || f_color[2] > 255)
		return (1);
	mlx->rgb_floor = ft_rgb(f_color[0], f_color[1], f_color[2]);
	return (0);
}

int			ft_elem_sky_color(char **line, t_data *mlx)
{
	char	*newline;
	int		f_color[3];

	newline = ft_strtrim(*line, "C ");
	free(*line);
	*line = NULL;
	f_color[0] = -1;
	f_color[1] = -1;
	f_color[2] = -1;
	if (ft_split_int(f_color, newline))
	{
		free(newline);
		return (1);
	}
	free(newline);
	if (f_color[0] < 0 || f_color[1] < 0 || f_color[2] < 0)
		return (1);
	if (f_color[0] > 255 || f_color[1] > 255 || f_color[2] > 255)
		return (1);
	mlx->rgb_sky = ft_rgb(f_color[0], f_color[1], f_color[2]);
	return (0);
}

int			ft_elem_resolution(char **line, t_data *mlx)
{
	char	*newline;

	newline = ft_strtrim(*line, "R");
	free(*line);
	*line = NULL;
	mlx->x = -1;
	mlx->y = -1;
	if (ft_split_res(newline, mlx))
	{
		free(newline);
		return (1);
	}
	free(newline);
	if ((mlx->x < 0) || (mlx->y < 0))
		return (1);
	return (0);
}

int			ft_map_element(char **line)
{
	static int	count;

	if (line[0][0] != 0 && count < 8)
	{
		count++;
		return (ft_check_elements(line));
	}
	if (count < 8)
		return (1);
	if (line[0][0] == 0)
		return (1);
	count = 0;
	return (0);
}
