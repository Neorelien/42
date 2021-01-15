/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:12:11 by awery             #+#    #+#             */
/*   Updated: 2021/01/13 16:25:55 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>

typedef struct s_lolol
{
	void	*mlx_ptr;
	void	*windows_identifier;
	int		a;
}				t_lolol;

int	mouuve(int ascii, t_lolol *param)
{
	printf("\n%d\n", ascii);
	int i = 0;
	if (ascii == 0)
	{
		param->a = param->a + 20;
		mlx_clear_window (param->mlx_ptr, param->windows_identifier);
		while (i++ < 230)
			mlx_pixel_put(param->mlx_ptr, param->windows_identifier, param->a, i, 0255076);
	}
	return (0);
}
int	exposetest(t_lolol *param)
{
	param->a++;
	printf("ouiouio");
	return (0);
}
	
int main()
{
	t_lolol huli;
	int		i = 0;
	huli.a = 0;

	huli.mlx_ptr = mlx_init();
	huli.windows_identifier =  mlx_new_window(huli.mlx_ptr, 500, 500, "bonjour");
	while (i++ < 230)
		mlx_pixel_put(huli.mlx_ptr,huli. windows_identifier, huli.a, i, 0255076);
	mlx_string_put(huli.mlx_ptr, huli.windows_identifier, 255, 255, 0255076, "YOO LA MIF" );
	mlx_key_hook(huli.windows_identifier, &mouuve, &huli);
	mlx_expose_hook(huli.windows_identifier, &exposetest, &huli);
	mlx_loop (huli.mlx_ptr);
}
