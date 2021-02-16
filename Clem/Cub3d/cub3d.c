/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 13:00:43 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:12:25 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

int		exit_game(t_mlx *mlx)
{
	ft_free_all(mlx);
	ft_free_textures(mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->tex_n.path = "./textures/brick.xpm";
	mlx->tex_e.path = "./textures/grass.xpm";
	mlx->tex_w.path = "./textures/stone.xpm";
	mlx->tex_s.path = "./textures/wood.xpm";
	mlx->tex_sprite.path = "./textures/metal.xpm";
	mlx->tex_n.malloc = 0;
	mlx->tex_e.malloc = 0;
	mlx->tex_w.malloc = 0;
	mlx->tex_s.malloc = 0;
	mlx->tex_sprite.malloc = 0;
	mlx->floor_color = 255 * 256 * 256 + 255 * 256 + 255;
	mlx->ceil_color = 255 * 256 * 256 + 255;
}

char	**ft_arg_check(int argc, char **argv, t_mlx *mlx)
{
	int len;

	if (argc < 2 || argc > 3)
	{
		mlx->error = ERROR_ARG_NB;
		ft_error(mlx);
	}
	if (argc == 3)
		ft_save_screen(mlx, argv);
	argv++;
	len = ft_strlen(*argv);
	if (argv[0][len - 4] != '.' || argv[0][len - 3] != 'c'
		|| argv[0][len - 2] != 'u' || argv[0][len - 1] != 'b')
	{
		mlx->error = NOT_MAP;
		ft_error(mlx);
	}
	count_size_map(*argv, mlx);
	return (argv);
}

void	ft_mlx_settings(char **argv, t_mlx *mlx)
{
	*mlx = window(*argv, *mlx);
	ft_init_mlx(mlx);
	mlx->mlx_ptr = mlx_init();
	mlx->game_win = mlx_new_window(mlx->mlx_ptr, mlx->win_width,
		mlx->win_height, *argv);
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->map.size_width,
		mlx->map.size_height);
	mlx->game.img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_width,
		mlx->win_height);
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
		&mlx->img.size_l, &mlx->img.endian);
	mlx->game.data = (int *)mlx_get_data_addr(mlx->game.img_ptr, &mlx->game.bpp,
		&mlx->game.size_l, &mlx->img.endian);
	*mlx = get_map(*argv, *mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.error = 0;
	argv = ft_arg_check(argc, argv, &mlx);
	if (mlx.error != SUCCESS)
		ft_error(&mlx);
	ft_mlx_settings(argv, &mlx);
	if (mlx.error != SUCCESS)
	{
		ft_error(&mlx);
	}
	ft_refresh_sprite(&mlx);
	frame(mlx);
	if (mlx.save == 1)
	{
		launch_save(&mlx);
		exit_game(&mlx);
	}
	mlx_hook(mlx.game_win, 2, 0, deal_key, &mlx);
	mlx_hook(mlx.game_win, 17, 0, exit_game, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
