/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 16:13:26 by cmoyal            #+#    #+#             */
/*   Updated: 2021/02/15 16:13:28 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "example.h"

void	ft_error_second(t_mlx *mlx)
{
	if (mlx->error == ERROR_NO_HERO)
		write(1, "No hero in map\n", 15);
	if (mlx->error == WRITE_ERROR)
		write(1, "Error during a write\n", 21);
	if (mlx->error == OPEN_ERROR)
		write(1, "Error during open\n", 18);
	if (mlx->error == ERROR_COLORS)
		write(1, "Error in colors\n", 16);
	if (mlx->error == COLOR_ERROR)
		write(1, "ERROR 606\n", 10);
	if (mlx->error == ERROR_TEX_N)
		write(1, "North textures error\n", 21);
	if (mlx->error == ERROR_TEX_S)
		write(1, "South textures error\n", 21);
	if (mlx->error == ERROR_TEX_E)
		write(1, "East textures error\n", 20);
	if (mlx->error == ERROR_TEX_W)
		write(1, "West textures error\n", 20);
	if (mlx->error == ERROR_TEX_SPRITE)
		write(1, "Sprite textures error\n", 22);
}

void	ft_error(t_mlx *mlx)
{
	write(1, "ERROR\n", 6);
	if (mlx->error == ERROR_ARG_NB)
		write(1, "Number of args aren't good\n", 27);
	if (mlx->error == NOT_MAP)
		write(1, "You don't put a map\n", 20);
	if (mlx->error == UNKNOW_ARG)
		write(1, "Unknow argument\n", 16);
	if (mlx->error == MALLOC_ERROR)
		write(1, "Error during malloc\n", 23);
	if (mlx->error == READ_ERROR)
		write(1, "Error during read\n", 18);
	if (mlx->error == TOO_MUCH_HERO)
		write(1, "Too much hero in map\n", 21);
	if (mlx->error == MAP_ERROR)
		write(1, "Error in map\n", 13);
	ft_error_second(mlx);
	exit(EXIT_FAILURE);
}

void	ft_error_tex_free(int selec, t_mlx *mlx)
{
	write(1, "ERROR\n", 6);
	if (selec == 0)
		if (mlx->tex_n.malloc)
			mlx->tex_n.malloc = -1;
	if (selec <= 1)
		if (mlx->tex_n.malloc)
			mlx->tex_s.malloc = -1;
	if (selec <= 2)
		if (mlx->tex_n.malloc)
			mlx->tex_e.malloc = -1;
	if (selec <= 3)
		if (mlx->tex_n.malloc)
			mlx->tex_w.malloc = -1;
	if (selec <= 4)
		if (mlx->tex_n.malloc)
			mlx->tex_sprite.malloc = -1;
}

void	ft_error_textures_second(t_mlx *mlx)
{
	if (mlx->error == ERROR_TEX_E)
	{
		ft_error_tex_free(2, mlx);
		write(1, "East textures error\n", 20);
	}
	else if (mlx->error == ERROR_TEX_W)
	{
		ft_error_tex_free(3, mlx);
		write(1, "West textures error\n", 20);
	}
	else if (mlx->error == ERROR_TEX_SPRITE)
	{
		ft_error_tex_free(4, mlx);
		write(1, "Sprite textures error\n", 22);
	}
}

void	ft_error_textures(t_mlx *mlx)
{
	if (mlx->error == ERROR_TEX_N)
	{
		ft_error_tex_free(0, mlx);
		write(1, "North textures error\n", 21);
	}
	else if (mlx->error == ERROR_TEX_S)
	{
		ft_error_tex_free(1, mlx);
		write(1, "South textures error\n", 21);
	}
	else if (mlx->error == ERROR_TEX_E || mlx->error == ERROR_TEX_W
		|| mlx->error == ERROR_TEX_SPRITE)
		ft_error_textures_second(mlx);
	exit_game(mlx);
}
