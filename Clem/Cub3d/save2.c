/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 02:55:31 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 13:44:57 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		ft_save(t_mlx *mlx)
{
	t_save save;

	save.height = mlx->win_height - 1;
	save.width = mlx->win_width;
	save.pad = (4 - ((int)save.width * 3) % 4) % 4;
	save.file_header = create_file_header(mlx, save.pad);
	save.img_header = create_img_header(save.height, save.width);
	if ((save.fd = open(SCREEN_PATH, O_WRONLY | O_CREAT, RIGHTS)) < 0)
	{
		return (OPEN_ERROR);
	}
	if (write_headers(&save) != SUCCESS)
	{
		close(save.fd);
		return (COLOR_ERROR);
	}
	if (write_colors(mlx, save.fd, save.height, save.width) != SUCCESS)
	{
		close(save.fd);
		return (COLOR_ERROR);
	}
	close(save.fd);
	return (SUCCESS);
}

int		launch_save(t_mlx *mlx)
{
	if ((mlx->error = ft_save(mlx)) != SUCCESS)
		ft_error(mlx);
	mlx->save = 0;
	return (SUCCESS);
}

void	ft_save_screen(t_mlx *mlx, char **argv)
{
	if (argv[2][0] == '-' && argv[2][1] == '-' && argv[2][2] == 's'
		&& argv[2][3] == 'a' && argv[2][4] == 'v' && argv[2][5] == 'e')
		mlx->save = 1;
	else
	{
		mlx->error = UNKNOW_ARG;
		ft_error(mlx);
	}
}
