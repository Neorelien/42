/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:27:32 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/14 20:22:43 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void	free_support(t_data *mlx)
{
	if (mlx->wall_one_path != NULL)
		free(mlx->wall_one_path);
	if (mlx->wall_two_path != NULL)
		free(mlx->wall_two_path);
	if (mlx->wall_three_path != NULL)
		free(mlx->wall_three_path);
	if (mlx->wall_four_path != NULL)
		free(mlx->wall_four_path);
}

void	ft_null_init(t_data *mlx)
{
	mlx->map = NULL;
	mlx->mlx_ptr = NULL;
	mlx->img_ptr = NULL;
	mlx->td_img_ptr = NULL;
	mlx->wone_img_ptr = NULL;
	mlx->wtwo_img_ptr = NULL;
	mlx->wthree_img_ptr = NULL;
	mlx->wfour_img_ptr = NULL;
	mlx->sprite_img_ptr = NULL;
	mlx->td_win_ptr = NULL;
	mlx->wall_one_path = NULL;
	mlx->wall_two_path = NULL;
	mlx->wall_three_path = NULL;
	mlx->wall_four_path = NULL;
	mlx->sprite_path = NULL;
	mlx->nb_sprite = 0;
}

void	ft_free_mlx(t_data *mlx)
{
	int i;
	int	o;

	o = 0;
	i = 0;
	if (mlx->map != NULL)
	{
		while (mlx->map[i])
			free(mlx->map[i++]);
		free(mlx->map[i]);
	}
	i = 0;
	free_support(mlx);
	while (i < mlx->nb_sprite)
		free(mlx->sprite_pos[mlx->nb_sprite - i++ - 1]);
	if (mlx->nb_sprite > 0)
		free(mlx->sprite_pos);
	if (mlx->sprite_path != NULL)
		free(mlx->sprite_path);
}

int		clean_exit(char *error, t_data *mlx)
{
	if (error != NULL)
		printf("Error\n %s\n", error);
	if (mlx->img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->td_img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->td_img_ptr);
	if (mlx->wone_img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wone_img_ptr);
	if (mlx->wtwo_img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wtwo_img_ptr);
	if (mlx->wthree_img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wthree_img_ptr);
	if (mlx->wfour_img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->wfour_img_ptr);
	if (mlx->sprite_img_ptr != NULL)
		mlx_destroy_image(mlx->mlx_ptr, mlx->sprite_img_ptr);
	if (mlx->td_win_ptr != NULL)
		mlx_destroy_window(mlx->mlx_ptr, mlx->td_win_ptr);
	ft_free_mlx(mlx);
	exit(0);
	return (1);
}

int		final_exit(t_data *mlx)
{
	clean_exit(NULL, mlx);
	return (0);
}
