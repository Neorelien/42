/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/24 18:08:00 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		ft_echo(t_parsing info, char ***env, t_utils *utils)
{
	int		i;
	int		flag;
	char	*str;
	int		flag_pipe;
	
	flag = 0;
	i = 0;
	flag_pipe = ft_next_is_pipe(info, *env, utils, 0);
	if (g_sig.pid == 0)
	{
		g_sig.pid = -2;
		fonction_router(info.next, env, utils);
		return (1);
	}
	else if (info.data && g_sig.pid != 0)
	{
		if (ft_strncmp(info.data[i], "-n", 3) == 0 && ++i)
			flag = 1;
		while (info.data[i])
		{	
			ft_putstr_fd(info.data[i], 1); 
			if (i != (int)ft_doubletab_len(info.data) - 1)
				ft_putchar_fd(' ', 1);
			i++;
		}
	}
	if (flag == 0)
		ft_putstr_fd("\n", 1);
/*	if (g_sig.pid > 0)
	{
		wait(NULL);
		g_sig.pid = -1;
		close(fd);
		return (0);
	}*/	
	return (1);
}
