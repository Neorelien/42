/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubetd_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:10:07 by aurelien          #+#    #+#             */
/*   Updated: 2021/02/17 16:48:03 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBETD_UTILS_H
# define CUBETD_UTILS_H

# include "minilibx/mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define RAD 0.0174533

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*td_win_ptr;
	void		*img_ptr;
	void		*td_img_ptr;
	char		**map;
	int			*data;
	int			*td_data;
	int			*xpm_data[5];
	int			x;
	int			y;
	int			y_td;
	int			x_td;
	int			y_dd;
	int			x_dd;
	int			ratio_map;
	int			amplitude;
	char		cardinal_point;
	char		ex_card_point;
	float		wall_height;
	int			start_sprite;
	int			wall_one_size[2];
	char		*wall_one_path;
	void		*wone_img_ptr;
	int			wall_two_size[2];
	char		*wall_two_path;
	void		*wtwo_img_ptr;
	int			wall_three_size[2];
	char		*wall_three_path;
	void		*wthree_img_ptr;
	int			wall_four_size[2];
	char		*wall_four_path;
	void		*wfour_img_ptr;
	int			sprite_size[2];
	char		*sprite_path;
	void		*sprite_img_ptr;
	int			rgb_wall;
	int			rgb_floor;
	int			rgb_sky;
	int			rgb_ray;
	int			**sprite_pos;
	int			ex_sprite_text;
	int			count_sprite;
	int			nb_sprite;
	float		sprite_direction;
	int			*ray_touch_sprite;
	int			start_looking;
	float		direction;
	float		ex_direction[2];
	float		initial_direction;
	int			nb_ray;
	int			save_pic;
}				t_data;

int				readelement_support(int element, int *check);
int				cross_clean_exit(t_data *mlx);
void			ft_cp_in_bmp(char *bmp, char *file_size, char *tmp,
		char *maltemp);
int				ft_init_data_xpm(t_data *mlx);
float			ft_floatcomp(float a, float b);
void			ft_put_colomn(int *x, int *y, t_data *mlx, int i);
void			write_pixel_sprite(t_data *mlx, int *i, int move_x, int move_y);
int				ft_cast_ray_sprite(t_data *mlx, int sprite_nb);
int				ft_sprite_width(int i, t_data *mlx, int nb_sprite);
int				write_pixel_move(t_data *mlx, int *i, int move_x, int move_y);
int				ft_y_len(char **str);
int				ft_check_elements(char **line);
int				ft_split_res(char *newline, t_data *mlx);
int				ft_split_int(int *f_color, char *newline);
int				ft_elem_floor_color(char **line, t_data *mlx);
int				ft_elem_sky_color(char **line, t_data *mlx);
int				ft_elem_resolution(char **line, t_data *mlx);
int				ft_display_cub(t_data *mlx);
void			orientation_suppor(int *pos, int *range, int *i);
void			ft_browse(t_data *mlx, int *x, int *y);
void			rc(t_data *mlx, int *i, int *loop);
int				ft_cast_ray(t_data *mlx);
int				write_pixel(t_data *mlx, int *i, int move_x, int move_y);
void			rc(t_data *mlx, int *i, int *loop);
void			maping_sup(int fd, char **line, t_data *mlx, int *i);
int				ft_check_argv(char **argv, int argc, t_data *mlx);
int				final_exit(t_data *mlx);
void			ft_null_init(t_data *mlx);
void			save_to_bmp(t_data *mlx);
void			ft_del_ray(t_data *mlx);
int				clean_exit(char *errort, t_data *mlx);
void			ft_free_mlx(t_data *mlx);
void			ft_sprite_pos(t_data *mlx);
void			ft_sprite_de_pos(t_data *mlx);
int				ft_put_texture_sprite(t_data *mlx, int i, long double county,
		int *y);
int				ft_put_texture(t_data *mlx, int i, long double county, int *y);
int				ft_init_xmp(t_data *mlx);
int				ft_variance(int a, int b);
int				ft_reset_ft();
int				ft_y_move(float sinus, int count);
int				ft_x_move(float cosinus, int count);
int				ft_3d_win_init(t_data *mlx);
int				ft_x(int i, t_data *mlx);
int				ft_y(int i, t_data *mlx);
void			ft_3d(t_data *mlx, int i);
void			ft_look(t_data *mlx);
int				ft_get_elements(char **argv, t_data *mlx);
int				ft_map_is_0(char **map, int y, int x, int *check);
int				ft_map_is_2(char **map, int y, int x);
int				ft_map_is_1(char **map, int y, int x, int *check);
int				ft_map_is_o(char **map, int y, int x, int *check);
int				ft_map_is_close(char **map, int *coor);
int				ft_check_map(char **map);
int				ft_map_element(char **line);
int				ft_display_init(t_data *mlx);
int				pos(t_data *mlx, int x, int y);
int				pos_td(t_data *mlx, int x, int y);
int				ft_rgb(int r, int g, int b);
int				ft_put_player(t_data *mlx);
int				ft_display_cub(t_data *mlx);
int				ft_player_move(int key, t_data *mlx);
int				ft_init_direction(t_data *mlx);

#endif
