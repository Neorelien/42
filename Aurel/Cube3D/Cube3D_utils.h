/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:10:07 by aurelien          #+#    #+#             */
/*   Updated: 2021/01/16 00:39:33 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minilibx/mlx.h"
# include "libft.h"

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

int			ft_get_elements(char **argv, t_data *mlx);
int			ft_map_element(char **line);
