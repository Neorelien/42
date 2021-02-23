/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:48:52 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/22 20:37:19 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"

# define PI 3.1415926535
# define RAD 0.0174533

typedef enum		e_error
{
	SUCCESS,
	ERROR_ARG_NB,
	MAP_ERROR,
	UNKNOW_ARG,
	NOT_MAP,
	PATH_ERROR,
	MALLOC_ERROR,
	READ_ERROR,
	ERROR_IN_PARS,
	TOO_MUCH_HERO,
	ERROR_NO_HERO,
	ERROR_TEX_N,
	ERROR_TEX_S,
	ERROR_TEX_E,
	ERROR_TEX_W,
	ERROR_TEX_NOT_PATH,
	ERROR_TEX_SPRITE,
	WRITE_ERROR,
	OPEN_ERROR,
	ERROR_COLORS,
	COLOR_ERROR,
	ERROR_TOO_MUCH_INFO
}					t_error;

typedef struct		s_hero
{
	int		forward;
	int		back;
	int		right;
	int		left;
	int		r_right;
	int		r_left;
	int		pos_x;
	int		pos_y;
	int		wall;
}					t_hero;

typedef struct		s_ray
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;
	double	deltadist_x;
	double	deltadist_y;
	double	plan_x;
	double	plan_y;
	int		x;
	int		map_x;
	int		map_y;
	double	move_speed;
	double	rot_speed;
	int		line_h;
	int		step_x;
	int		step_y;
	double	sidedist_y;
	double	sidedist_x;
	int		draw_start;
	int		draw_end;
	double	dist;
	int		side;
	char	angle;
	int		hit;
	double	camerax;
	double	raydir_x;
	double	raydir_y;
}					t_ray;

typedef struct		s_game
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}					t_game;

typedef struct		s_map
{
	int		x;
	int		y;
	int		temp_y;
	int		temp_x;
	int		count_w;
	int		count_h;
	int		size_height;
	int		size_width;
	int		count;
	int		i;
	int		fd;
}					t_map;

typedef struct		s_textures
{
	void	*img;
	int		bpp;
	int		size_l;
	int		endian;
	int		*data;
	int		width;
	int		height;
	char	*path;
	int		malloc;
}					t_textures;

typedef struct		s_angle
{
	int	x;
	int	y;
	int	first;
	int second;
	int	min;
}					t_angle;

typedef struct		s_texpos
{
	double	step;
	double	pos;
	int		txy;
	int		txx;
	int		dir;
}					t_texpos;

typedef struct		s_info
{
	int floor_c[3];
	int ceiling_c[3];
}					t_info;

typedef struct		s_sprite
{
	int		*order;
	double	*dist;
	double	spritex;
	double	spritey;
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		sprite_h;
	int		drawstartx;
	int		drawstarty;
	int		drawendy;
	int		drawendx;
	int		sprite_w;
	double	*zbuffer;
}					t_sprite;

typedef struct		s_disprite
{
	double		x;
	double		y;
}					t_disprite;

typedef struct		s_color
{
	int r;
	int g;
	int b;
	int tot;
}					t_color;

typedef struct		s_mlx
{
	void		*mlx_ptr;
	void		*game_win;
	int			max_width;
	int			max_height;
	t_ray		ray;
	t_hero		hero;
	t_textures	texture;
	t_textures	tex_n;
	t_textures	tex_s;
	t_textures	tex_e;
	t_textures	tex_w;
	t_textures	tex_sprite;
	t_game		game;
	t_map		map;
	t_texpos	tex_pos;
	t_sprite	sprite;
	t_disprite	*spr;
	int			init[4];
	char		**card;
	int			nb_sprite;
	int			nb_disprite;
	int			error;
	int			win_width;
	int			win_height;
	int			color_f;
	int			color_c;
	int			save;
	int			nblines;
	int			sizeline;
	int			inmap;
	int			count;
	int			wrongcharmap;
	int			start;
	int			i;
	double		wall_x;
	int			pad;
	int			super_width;
	int			super_height;
}					t_mlx;

void				ft_parsing_info(char *map_path, t_mlx *mlx);
void				ft_textures(char *info, t_mlx *mlx);
void				ft_error(t_mlx *mlx, char *error);
void				ft_make_color_cf(char *str, t_mlx *mlx);
void				ft_save_screen(t_mlx *mlx, char **argv);
int					ft_isalpha(char c);
int					ft_isnum(char c);
int					ft_exit(t_mlx *mlx);
int					ft_is_map(char *map, t_mlx *mlx);
int					window(t_mlx *mlx, int count, char *res);
int					ft_copy_map(char *map, t_mlx *mlx);
void				ft_init_sprite(t_mlx *mlx);
t_mlx				check_map(char **map, t_mlx mlx);
int					ft_mlx(t_mlx *mlx);
void				window_second(t_mlx *mlx);
void				get_textures_data(t_mlx *mlx);
void				ft_draw_texture(t_mlx *mlx, int x, int y);
int					ft_raycasting(t_mlx *mlx);
void				ft_rotate_left(t_mlx *mlx, double dir_x_prec);
void				ft_rotate_right_left(t_mlx *mlx);
void				ft_left_right(t_mlx *mlx);
void				ft_forward_back(t_mlx *mlx);
void				ft_save(t_mlx *mlx);
void				ft_sprite(t_mlx *mlx);
void				ft_dist_order(t_mlx *mlx);
void				ft_calculs(t_mlx *mlx, int i);
void				ft_draw_spr(t_mlx *mlx, int y, int txx, int s);
int					ft_press_key(int key, t_mlx *mlx);
int					ft_ismap(char c);
int					ft_release_key(int key, t_mlx *mlx);
void				ft_color_column(t_mlx *mlx);
void				ft_init_texture(t_mlx *mlx);
int					ft_ispos(char c, t_mlx *mlx);
#endif
