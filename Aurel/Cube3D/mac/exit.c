/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 00:01:08 by Aurelien          #+#    #+#             */
/*   Updated: 2021/03/03 19:28:40 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int		ft_supsup(int *temp, int *coor, char **map)
{
	if ((temp[1] = coor[1]) == coor[1] && map[coor[1]][coor[0]] != '0')
		return (0);
	if ((int)ft_strlen(map[coor[1] - 1]) <= coor[0] - 1)
		return (1);
	if ((int)ft_strlen(map[coor[1] + 1]) <= coor[0] - 1)
		return (1);
	return (-1);
}

int		ft_nofloor(char c)
{
	if (c != '0' && c != '2' && c != 'N' && c != 'E' &&
			c != 'W' && c != 'S' && c != '1')
		return (1);
	return (0);
}

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

int		readelement_support(int element, int *check)
{
	if (check[0] != 10 && (check[0] = 0) == 0)
		while (check[0]++ < 9)
			check[check[0]] = 0;
	if (check[element] == 1)
		return (1);
	else
		return (0);
}
