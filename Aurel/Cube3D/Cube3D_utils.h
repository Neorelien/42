/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:10:07 by aurelien          #+#    #+#             */
/*   Updated: 2021/01/15 20:10:02 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "libft.h"

typedef struct	s_elem
{
	int	x;
	int	y;
}				t_elem;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	t_elem	element;	
}				t_data;
