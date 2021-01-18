/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 00:33:28 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/16 01:19:21 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"

int			ft_check_elements(char **line)
{
	if (line[0][0] == 'R')
		return (2);
	if (line[0][0] == 'F')
		return (3);
	if (line[0][0] == 'C')
		return (4);
	if (line[0][0] == 'S')
		return (5);
	if (line[0][0] == 'N' && line[0][1] == 'O')
		return (6);
	if (line[0][0] == 'S' && line[0][1] == 'O')
		return (7);
	if (line[0][0] == 'E' && line[0][1] == 'A')
		return (8);
	if (line[0][0] == 'W' && line[0][1] == 'E')
		return (9);
	return (-1);
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

int			ft_elem_resolution(char **line, t_data *mlx)
{
	char	**coordinates;
	char	*newline;

	newline = ft_strtrim(*line, "R");
	free(*line);
	coordinates = ft_split(newline, ' ');
	free(newline);
	mlx->element.x = ft_atoi(coordinates[0]);
	mlx->element.y = ft_atoi(coordinates[1]);
	free(coordinates[1]);
	free(coordinates);
	if ((mlx->element.x < 0) || (mlx->element.y < 0))
		return (1);
	return (0);
}

int			ft_read_elem(char **line, t_data *mlx, int element)
{
	if (element == 1)
		return (0);
	if (element == 2)
		return(ft_elem_resolution(line, mlx));
	if (element == 3)
		return (0);
	if (element == 4)
		return (0);
	if (element == 5)
		return (0);
	if (element == 6)
		return (0);
	if (element == 7)
		return (0);
	if (element == 8)
		return (0);
	if (element == 9)
		return (0);
	return (1);
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
	{
		if (element == -1)
		{
			close(fd);
			free(*line);
			free(line);
			return (1);
		}
		if (ft_read_elem(line, mlx, element))
		{
			close(fd);
			free(*line);
			free(line);
			return (1);
		}
		free(*line);
		if (get_next_line(fd, line) < 1)
		{
			close(fd);
			free(*line);
			free(line);
			return (1);
		}
	}
	free(*line);
	while (get_next_line(fd, line) > 0)
		free(*line);
	free(*line);
	free(line);
	return (0);
}
