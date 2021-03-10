/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:16:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/10 16:02:43 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		echo(t_parsing info, char ***env, t_utils *utils)
{
	int		i;
	int		flag;
	int		fd;
	int		j;
	char	*str;
	
	flag = 0;
	i = 0;
	fd = write_with_separator(info, *env, utils);
	if (utils->cpid == 0)
		echo(info.next, env, utils);
	else if (info.data && utils->pid == -1)
	{
		if (ft_strncmp(info.data[i], "-n", 3) == 0 && ++i)
			flag = 1;	
		while (info.data[i])
		{
			j = 0;
			while (info.data[i][j])
			{
				if (info.data[i][j] == '$' && !ft_isspace(info.data[i][j]))
				{
					if ((str = find_in_env(*env, info.data[i] + 1)) != NULL)
					{
						ft_putstr_fd(str, fd);
						free(str);
					}
					while (!ft_isspace(info.data[i][j]))
						j++;
				}
				ft_putchar_fd(info.data[i][j], fd);
				j++;
			}
			if (i != (int)ft_doubletab_len(info.data) - 1)
				ft_putchar_fd(' ', fd);
			i++;
		}
	}
	else 
		return (0);
	if (flag == 0)
		ft_putstr_fd("\n", fd);
	if (fd != 1)
		close(fd);
	return (1);
}
