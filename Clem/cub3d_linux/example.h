/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   example.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:48:52 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/16 20:16:04 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXAMPLE_H
# define EXAMPLE_H

# include <math.h>
# include "./minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line/get_next_line.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define PI 3.1415926535
# define RAD 0.0174533
# define BYTES_PER_PIX 3
# define FILE_HEADER_SIZE 14
# define IMG_HEADER_SIZE 40
# define COMPRESSION 24
# define SCREEN_PATH "screen.bmp"
# define RIGHTS 777

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
	COLOR_ERROR
}					t_error;

typedef struct		s_save
{
	int				height;
	int				width;
	int				pad;
	unsigned char	*file_header;
	unsigned char	*img_header;
	int				fd;
}					t_save;

typedef struct		s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}					t_img;

typedef struct		s_hero
{
	float	pos_x;
	float	pos_y;
	float	pdx;
	float	pdy;
	float	tdx;
	float	tdy;
	float	ray_a;
	float	pos_a;
	float	cos_a;
	int		wall;

}					t_hero;

typedef struct		s_ray
{
	int		ligne;
	int		nb_line;
	int		dist[601];
	float	pos_y;
	float	pos_x;
	float	line_h;
	float	line_o;
	int		height;
	float	i;
	char	angle;
	char	tex_be;
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
	char	**map;
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
	float	ty_step;
	float	ty_off;
	int		y;
	float	ty;
	float	tx;
	float	txy;
	float	ta;
}					t_texpos;

typedef struct		s_info
{
	int floor_c[3];
	int ceiling_c[3];
}					t_info;

typedef struct		s_sprite
{
	float	pos_a;
	int		width;
	float	y_prec;
	int		count_h;
	int		count_w;
	float	pos_x;
	float	pos_y;
	float	pdx;
	float	pdy;
	int		coord_x;
	int		coord_y;
}					t_sprite;

typedef struct		s_disprite
{
	int			x;
	int			y;
	int			dist;

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
	void		*win;
	void		*game_win;
	int			max_width;
	int			max_height;
	t_img		img;
	t_hero		hero;
	t_textures	tex_n;
	t_textures	tex_s;
	t_textures	tex_e;
	t_textures	tex_w;
	t_textures	tex_sprite;
	t_game		game;
	t_info		info;
	t_map		map;
	t_texpos	tex_pos;
	t_sprite	*sprite;
	t_disprite	*sprite_here;
	t_sprite	clear_sprite;
	char		starter;
	int			nb_sprite;
	int			nb_disprite;
	int			error;
	int			win_width;
	int			win_height;
	int			floor_color;
	int			ceil_color;
	int			save;
}					t_mlx;

void				ft_refresh_sprite(t_mlx *mlx);
void				ft_putchar(char c);
int					ft_isalpha(int c);
int					ft_ismaj(char c);
int					ft_isnum(char c);
t_mlx				check_map(char **map, t_mlx mlx);
t_mlx				get_sprite(char **map, t_mlx mlx);
t_mlx				get_textures_data(t_mlx mlx);
int					take_info(char **info, t_mlx *mlx, int count);
char				*make_textures_path(char *info, t_mlx *mlx);
void				ft_double_pointer_free(char **tab, int size, int all);
void				set_in_char(unsigned char *start, int value);
unsigned char		*create_file_header(t_mlx *mlx, int pad);
unsigned char		*create_img_header(int height, int width);
int					write_headers(t_save *save);
int					write_colors(t_mlx *mlx, int fd, int height, int width);
int					ft_save(t_mlx *mlx);
int					launch_save(t_mlx *mlx);
void				count_size_map(char *path, t_mlx *mlx);
t_mlx				get_pixel(char **map, t_mlx mlx);
t_mlx				get_hero(char **map, t_mlx mlx);
t_mlx				get_map(char *path, t_mlx mlx);
void				ft_mlx_settings(char **argv, t_mlx *mlx);
t_mlx				window(char *path, t_mlx mlx);
int					deal_key(int key, t_mlx *mlx);
void				ft_save_screen(t_mlx *mlx, char **argv);
void				ft_free_all(t_mlx *mlx);
void				ft_error(t_mlx *mlx);
int					ft_ispos(char c, t_mlx *mlx);
int					exit_game(t_mlx *mlx);
void				init_color_fc(t_mlx mlx);
int					ft_issprite(t_mlx mlx);
void				clear_hero(t_mlx mlx);
int					ft_iswall(t_mlx mlx);
t_mlx				angle(t_mlx mlx, t_ray ray);
t_mlx				hero_turn(int key, t_mlx mlx);
t_mlx				hero_new_pos(int key, t_mlx mlx);
void				frame(t_mlx first_mlx);
void				ft_textures_angle(t_mlx mlx, t_ray ray);
char				ft_isangle(t_mlx mlx, t_ray ray);
int					ft_sprite_textures_x(t_mlx mlx);
int					ft_count_sprite(t_mlx mlx);
void				make_textures(t_mlx mlx, t_ray ray);
void				range_ray(t_ray ray, t_mlx mlx);
t_mlx				move_hero(t_mlx mlx);
void				ft_make_color_cf(char *str, t_mlx *mlx);
void				ft_error_textures(t_mlx *mlx);
void				ft_free_textures(t_mlx *mlx);
int					ft_min(int a, int b);
int					ft_abs(int a);
int					ft_ismap(char c);
void				textures_check(t_mlx *mlx);
#endif
