/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:10:07 by aurelien          #+#    #+#             */
/*   Updated: 2021/01/18 11:47:44 by awery            ###   ########.fr       */
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
int			ft_map_is_0(char **map, int y, int x, int *check);
int			ft_map_is_2(char **map, int y, int x, int *check);
int			ft_map_is_1(char **map, int y, int x, int *check);
int			ft_map_is_O(char **map, int y, int x, int *check);
int			ft_map_is_close(char **map, int y, int x, int *check);
int			ft_check_map(char **map);
int			ft_map_element(char **line);
int			ft_map_display(t_data *mlx);
