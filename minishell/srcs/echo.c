/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/09 14:39:57 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		ft_echo_flag(t_parsing info, int *i)
{
	int flag;
	int o;

	flag = 0;
	o = 1;
	while (ft_strncmp(info.data[*i], "-n", 1) == 0)
	{
		while (info.data[*i][o] && info.data[*i][o] == 'n')
			o++;
		if (info.data[*i][o] == 0)
		{
			flag = 1;
			i[0]++;
		}
		else
			break ;
	}
	return (flag);
}

int		ft_echo(t_parsing info, char ***env, t_utils *utils)
{
	int		i;
	int		flag;

	(void)env;
	i = 0;
	flag = 0;
	if (info.data)
	{
		flag = ft_echo_flag(info, &i);
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
	if (reset_fd_one(utils))
		;
	return (0);
}
