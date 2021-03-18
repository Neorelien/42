/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/18 13:13:03 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		ft_echo(t_parsing info, char ***env, t_utils *utils)
{
	int		i;
	int		flag;
	int		fd;
	char	*str;

	flag = 0;
	i = 0;
	fd = write_with_separator(info, *env, utils, 1);
	if (utils->cpid == 0)
	{
		utils->cpid = -2;
		fonction_router(info.next, env, utils);
	}
	else if (info.data && utils->cpid < 0)
	{
		if (ft_strncmp(info.data[i], "-n", 3) == 0 && ++i)
			flag = 1;
		while (info.data[i])
		{	
			ft_putstr_fd(info.data[i], fd); 
			if (i != (int)ft_doubletab_len(info.data) - 1)
				ft_putchar_fd(' ', fd);
			i++;
		}
	}
	else
	{
		wait(NULL);
		utils->cpid = -1;
		return (0);
	}
	if (flag == 0)
		ft_putstr_fd("\n", fd);
//	if (fd != 1)
//		close(fd);
	return (1);
}
