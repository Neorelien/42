/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/24 23:59:24 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		ft_echo(t_parsing info, char ***env, t_utils *utils)
{
	int		i;
	int		flag;

	(void)env;
	flag = 0;
	i = 0;
	if (info.data)
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
	if (reset_fd_one(utils))
		;
	return (0);
}
