/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 18:02:37 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 21:01:28 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**ft_arg_check(int argc, char **argv, t_mlx *mlx)
{
	int len;

	mlx->save = 0;
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\nArguments Invalids\n", 25);
		exit(EXIT_FAILURE);
	}
	if (argc == 3)
		ft_save_screen(mlx, argv);
	argv++;
	len = ft_strlen(*argv);
	if (argv[0][len - 4] != '.' || argv[0][len - 3] != 'c'
		|| argv[0][len - 2] != 'u' || argv[0][len - 1] != 'b')
	{
		write(1, "Error\nMap name invalid\n", 23);
		exit(EXIT_FAILURE);
	}
	return (argv);
}

void	ft_init_more(t_mlx *mlx)
{
	mlx->color_f = -1;
	mlx->color_c = -1;
	mlx->init[0] = 0;
	mlx->init[1] = 0;
	mlx->init[2] = 0;
	mlx->ray.dir_x = 0;
	mlx->ray.dir_y = 0;
	mlx->ray.plan_x = 0;
	mlx->ray.plan_y = 0;
	mlx->super_width = 0;
	mlx->super_height = 0;
	mlx->mlx_ptr = NULL;
}

void	ft_init(t_mlx *mlx)
{
	mlx->tex_n.path = NULL;
	mlx->tex_s.path = NULL;
	mlx->tex_w.path = NULL;
	mlx->tex_e.path = NULL;
	mlx->tex_sprite.path = NULL;
	mlx->tex_n.malloc = 0;
	mlx->tex_s.malloc = 0;
	mlx->tex_w.malloc = 0;
	mlx->tex_e.malloc = 0;
	mlx->tex_sprite.malloc = 0;
	mlx->win_height = 0;
	mlx->win_width = 0;
	mlx->nblines = 0;
	mlx->sizeline = 0;
	mlx->card = NULL;
	mlx->inmap = 0;
	mlx->count = 0;
	mlx->wrongcharmap = 0;
	mlx->start = 0;
	mlx->i = 0;
	mlx->spr = NULL;
	mlx->sprite.dist = NULL;
	mlx->sprite.order = 0;
	mlx->nb_sprite = 0;
	ft_init_more(mlx);
}

int		main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.error = SUCCESS;
	argv = ft_arg_check(argc, argv, &mlx);
	ft_init(&mlx);
	ft_parsing_info(*argv, &mlx);
	return (0);
}
