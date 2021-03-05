/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/05 14:54:10 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

static int echo_second(t_parsing info, int fd)
{
	if ((fd = write_with_separator(info)) <= 0)
	{
		ft_putstr_fd("zsh: no such file or directory: ", 1);
		ft_putstr_fd(info.next->objet, 1);
		ft_putchar_fd('\n', 1);
		return (-1);
	}
	return (fd);
}
int		echo(t_parsing info)
{
	int		i;
	int		flag;
	int		fd;
	
	flag = 0;
	i = 0;
	fd = 1;
	if (info.data)
	{
		if (ft_strncmp(info.data[i], "-n", 3) == 0 && ++i)
			flag = 1;
		if ((fd = echo_second(info, fd)) <= 0)
			return (-1);
		while (info.data[i])
		{
			write(fd, info.data[i], ft_strlen(info.data[i]));
			if (i != (int)ft_doubletab_len(info.data) - 1)
				ft_putchar_fd(' ', fd);
			i++;
		}
	}
	if (flag == 0)
		ft_putstr_fd("\n", fd);
	if (fd != 1)
		close(fd);
	return (1);
}
