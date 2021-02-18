/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:13:51 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/13 18:47:09 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int	ft_init_data_xpm(t_data *mlx)
{
	int	b_p;
	int	end;
	int	s_l;

	if ((mlx->xpm_data[0] = (int*)mlx_get_data_addr(mlx->wone_img_ptr,
					&b_p, &s_l, &end)) == NULL)
		return (1);
	if ((mlx->xpm_data[1] = (int*)mlx_get_data_addr(mlx->wtwo_img_ptr,
					&b_p, &s_l, &end)) == NULL)
		return (1);
	if ((mlx->xpm_data[2] = (int*)mlx_get_data_addr(mlx->wthree_img_ptr,
					&b_p, &s_l, &end)) == NULL)
		return (1);
	if ((mlx->xpm_data[3] = (int*)mlx_get_data_addr(mlx->wfour_img_ptr,
					&b_p, &s_l, &end)) == NULL)
		return (1);
	if ((mlx->xpm_data[4] = (int*)mlx_get_data_addr(mlx->sprite_img_ptr,
					&b_p, &s_l, &end)) == NULL)
		return (1);
	return (0);
}
