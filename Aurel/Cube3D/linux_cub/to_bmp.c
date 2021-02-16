/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:59:52 by awery             #+#    #+#             */
/*   Updated: 2021/02/14 20:44:41 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubetd_utils.h"

void			ft_write_pixel_bmp(t_data *mlx, int fd)
{
	int				h;
	int				l;
	unsigned char	*temp;

	h = mlx->y_td - 1;
	temp = malloc(sizeof(char) * 4);
	while (h >= 0)
	{
		l = 0;
		while (l < mlx->x_td)
		{
			ft_memset(temp, 0, 16);
			ft_memcpy(temp, &mlx->td_data[pos_td(mlx, l, h)], 16);
			write(fd, &temp[0], 1);
			write(fd, &temp[1], 1);
			write(fd, &temp[2], 1);
			l++;
		}
		h--;
	}
	free(temp);
}

void			height_width(t_data *mlx, char *bmp)
{
	char	*temp;
	char	*tempf;

	temp = ft_itoa(mlx->x_td);
	tempf = ft_convert_base(temp, "0123456789", "0123456789abcdef");
	ft_cp_in_bmp(bmp, tempf, NULL, NULL);
	free(temp);
	free(tempf);
	temp = ft_itoa(mlx->y_td);
	tempf = ft_convert_base(temp, "0123456789", "0123456789abcdef");
	ft_cp_in_bmp(&bmp[4], tempf, NULL, NULL);
	free(temp);
	free(tempf);
}

static void		supp(t_data *mlx, char *bmp, char *file_size_ch)
{
	char *temp;

	bmp[10] = 54;
	bmp[14] = 40;
	height_width(mlx, &bmp[18]);
	bmp[26] = 1;
	bmp[28] = 24;
	temp = ft_itoa((mlx->x_td * 3) * mlx->y_td);
	file_size_ch = ft_convert_base(temp, "0123456789", "0123456789abcdef");
	free(temp);
	free(file_size_ch);
}

void			create_image(t_data *mlx, int fd)
{
	char	*temp;
	char	*file_size_ch;
	char	*bmp;
	int		i;
	int		pad;

	i = 0;
	pad = (4 - (mlx->x_td * 3) % 4) % 4;
	bmp = malloc(sizeof(char) * 54);
	while (i < 54)
		bmp[i++] = 0;
	i = 0;
	bmp[0] = 'B';
	bmp[1] = 'M';
	temp = ft_itoa(54 + (mlx->y_td * (mlx->x_td + pad) * 3));
	file_size_ch = ft_convert_base(temp, "0123456789", "0123456789abcdef");
	free(temp);
	ft_cp_in_bmp(&bmp[2], file_size_ch, NULL, NULL);
	free(file_size_ch);
	supp(mlx, bmp, file_size_ch);
	write(fd, bmp, 54);
	ft_write_pixel_bmp(mlx, fd);
	free(bmp);
}

void			save_to_bmp(t_data *mlx)
{
	int		fd;

	if ((fd = open("capture.bmp", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) != -1)
	{
		create_image(mlx, fd);
		close(fd);
		cross_clean_exit(mlx);
	}
	else
		clean_exit("fichier bmp", mlx);
}
