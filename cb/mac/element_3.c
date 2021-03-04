/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 15:43:15 by Aurelien          #+#    #+#             */
/*   Updated: 2021/02/23 15:19:31 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

int		ft_check_elements(char **line)
{
	if (line[0][0] == 'R')
		return (2);
	if (line[0][0] == 'F')
		return (3);
	if (line[0][0] == 'C')
		return (4);
	if (line[0][0] == 'N' && line[0][1] == 'O')
		return (6);
	if (line[0][0] == 'S' && line[0][1] == 'O')
		return (7);
	if (line[0][0] == 'S')
		return (5);
	if (line[0][0] == 'E' && line[0][1] == 'A')
		return (8);
	if (line[0][0] == 'W' && line[0][1] == 'E')
		return (9);
	return (-1);
}

int		split_int_sup(int *f_color, int o, int *i, char *newline)
{
	if (o == 3)
		return (1);
	if (f_color[o] == -1)
		f_color[o] = newline[*i] - 48;
	else
		f_color[o] = f_color[o] * 10 + (newline[*i] - 48);
	*i = *i + 1;
	return (0);
}

int		ft_split_int(int *f_color, char *newline)
{
	int i;
	int	o;
	int	ex_vir;

	ex_vir = 0;
	i = 0;
	o = 0;
	while (newline[i])
	{
		if (newline[i] == ' ')
			i++;
		else if (newline[i] == ',')
		{
			if (ex_vir == 1 || o++ == 2)
				return (1);
			i++;
			ex_vir = 1;
		}
		else if (newline[i] >= '0' && newline[i] <= '9' && (ex_vir = 0) == 0)
			split_int_sup(f_color, o, &i, newline);
		else
			return (1);
	}
	return (0);
}

int		split_res_sup(t_data *mlx, int o, int i, char *newline)
{
	if (o == 2)
		return (1);
	if (o == 0 && mlx->x == -1)
		mlx->x = newline[i] - 48;
	else if (o == 0)
		mlx->x = mlx->x * 10 + (newline[i] - 48);
	else if (o == 1 && mlx->y == -1)
		mlx->y = newline[i] - 48;
	else if (o == 1)
		mlx->y = mlx->y * 10 + (newline[i] - 48);
	return (0);
}

int		ft_split_res(char *newline, t_data *mlx)
{
	int i;
	int	o;
	int	ex_nb;

	ex_nb = 0;
	i = 0;
	o = 0;
	while (newline[i])
	{
		if (newline[i] == ' ')
		{
			if (ex_nb == 1 && (ex_nb = 0) == 0)
				o++;
			i++;
		}
		else if (newline[i] >= '0' && newline[i] <= '9' && (ex_nb = 1))
		{
			if (split_res_sup(mlx, o, i++, newline))
				return (1);
		}
		else
			return (1);
	}
	return (0);
}
