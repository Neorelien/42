/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3D.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:14:40 by Aurelien          #+#    #+#             */
/*   Updated: 2021/01/14 18:43:05 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cube3D_utils.h"

int	ft_map_init(int argc, char *argv)
{
	int		fd;
	char	*line;

	if (argc != 1)
		return (1);
	fd = open(argv, O_RDONLY);
	get_next_line(fd, *map);
	return (0);	
}

int main(int argc, char *argv)
{
	if (ft_map_init(argc, argv))
		return (1);
	return (0);
}
