/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/04 11:14:59 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell_utils.h"
/*
int	echo_separator(t_parsing info)
{
	
}
*/
int		echo(t_parsing info)
{
	int		i;
	int		flag;
	int		fd;

	i = 0;
	if (ft_doubletab_len(info.option) > 1)
		return (0);
	if (ft_strncmp(info.option[0], "-n", 3) == 0)
		flag = 1;
	else if (info.option[0] == NULL)
		flag = 0;
	else
		return (0);
	fd = echo_separator(info);
	while (info.data[i])
	{
		write(1, info.data[i], ft_strlen(info.data[i]));
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", 1);
	return (1);
}
