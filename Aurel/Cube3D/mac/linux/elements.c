/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:33:28 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/17 20:51:10 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void		elem_text_support(char **line, t_data *mlx, int element, char *text)
{
	if (element == 8)
	{
		text = ft_strtrim(*line, "EA ");
		free(*line);
		mlx->wall_three_path = text;
	}
	if (element == 9)
	{
		text = ft_strtrim(*line, "WE ");
		free(*line);
		mlx->wall_four_path = text;
	}
	if (element == 5)
	{
		text = ft_strtrim(*line, "S ");
		free(*line);
		mlx->sprite_path = text;
	}
}

int			ft_elem_text(char **line, t_data *mlx, int element)
{
	char	*text;

	if (element == 6)
	{
		text = ft_strtrim(*line, "NO ");
		free(*line);
		mlx->wall_one_path = text;
	}
	if (element == 7)
	{
		text = ft_strtrim(*line, "SO ");
		free(*line);
		mlx->wall_two_path = text;
	}
	elem_text_support(line, mlx, element, text);
	*line = NULL;
	return (0);
}

int			ft_read_elem(char **line, t_data *mlx, int element)
{
	static int check[10];

	if (readelement_support(element, check))
		return (1);
	if (element == 1)
		return (0);
	if (element == 2 && (check[element] = 1))
		return (ft_elem_resolution(line, mlx));
	if (element == 3 && (check[element] = 1))
		return (ft_elem_floor_color(line, mlx));
	if (element == 4 && (check[element] = 1))
		return (ft_elem_sky_color(line, mlx));
	if (element == 5 && (check[element] = 1))
		return (ft_elem_text(line, mlx, element));
	if (element == 6 && (check[element] = 1))
		return (ft_elem_text(line, mlx, element));
	if (element == 7 && (check[element] = 1))
		return (ft_elem_text(line, mlx, element));
	if (element == 8 && (check[element] = 1))
		return (ft_elem_text(line, mlx, element));
	if (element == 9 && (check[element] = 1))
		return (ft_elem_text(line, mlx, element));
	return (1);
}

int			get_elem_support(t_data *mlx, int *element, char **line, int fd)
{
	if (*element == -1)
	{
		close(fd);
		free(*line);
		free(line);
		return (1);
	}
	if (ft_read_elem(line, mlx, *element))
	{
		close(fd);
		free(*line);
		free(line);
		return (1);
	}
	if (*line != NULL)
		free(*line);
	if (get_next_line(fd, line) < 1)
	{
		close(fd);
		free(*line);
		free(line);
		return (1);
	}
	return (0);
}

int			ft_get_elements(char **argv, t_data *mlx)
{
	int		fd;
	char	**line;
	int		element;

	fd = open(argv[1], O_RDONLY);
	if ((line = malloc(sizeof(char*))) == NULL)
		return (1);
	if (get_next_line(fd, line) == -1)
	{
		close(fd);
		free(line);
		return (1);
	}
	while (((element = ft_map_element(line)) != 0))
		if (get_elem_support(mlx, &element, line, fd))
			return (1);
	free(*line);
	while (get_next_line(fd, line) > 0)
		free(*line);
	free(*line);
	free(line);
	return (0);
}
