/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/09 13:22:04 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		echo(t_parsing info, char ***env)
{
	int		i;
	int		flag;
	int		fd;
	int		j;
	
	flag = 0;
	i = 0;
	fd = 1;
	if (info.data)
	{
		if (ft_strncmp(info.data[i], "-n", 3) == 0 && ++i)
			flag = 1;
		fd = write_with_separator(info);
		while (info.data[i])
		{
			while (info.data[i][j])
			{
				if (info.data[i][j] == '$' && !ft_isspace(info.data[i][j]))
					
				ft_putchar_fd(info.data[i][j], fd);
			}
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
