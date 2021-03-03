/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/03 15:58:29 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minishell_utils.h"

int		echo(t_parsing info)
{
	int		i;

	i = 0;
	if (ft_doubletab_len(info.option) > 1)
		return (0);
	while (info.data[i])
	{
		write(1, info.data[i], ft_strlen(info.data[i]));
		i++;
	}
	return (1);
}
