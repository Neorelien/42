/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/04 12:08:25 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell_utils.h"

int	echo_separator(t_parsing info)
{
	int sep;

	if ((sep = is_separator(info.separator)) == 0)
		return (1);
	if (sep == 1)
		return (1);
	else if (sep == 2)
		return (2);
	else if (sep == 3)
		return (open(info.next->objet, O_RDWR | O_CREAT, 644 | O_DIRECTORY));
	else if (sep == 4)
		return (1);
	else
		return (open(info.next->objet, O_RDWR | O_CREAT, 644 | O_DIRECTORY));
}

int		echo(t_parsing info)
{
	int		i;
	int		flag;
	int		fd;

	i = 0;
	if (ft_doubletab_len(info.option) > 1)
		return (0);
	if (ft_strncmp(info.data[i], "-n", 3) == 0 && ++i)
		flag = 1;
	if ((fd = echo_separator(info)) <= 0)
		return (-1);
	while (info.data[i])
	{
		write(1, info.data[i], ft_strlen(info.data[i]));
		i++;
	}
	if (flag == 0)
		ft_putstr_fd("\n", 1);
	return (1);
}
