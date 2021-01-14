/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:10:07 by aurelien          #+#    #+#             */
/*   Updated: 2021/01/14 18:23:29 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft.h"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		*map;
}				t_mlx;
