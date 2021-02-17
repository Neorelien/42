/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:01:08 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/14 20:52:46 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int		cross_clean_exit(t_data *mlx)
{
	printf("Vous avez fini de jouer\n");
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