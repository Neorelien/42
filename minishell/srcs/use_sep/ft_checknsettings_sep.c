/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checknsettings_sep.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:52:44 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/13 14:01:56 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

void	check_to_next(t_parsing info, char ***env, t_utils *utils)
{
	if (is_separator(info.separator) == 0 || is_separator(info.separator) == 2)
		return ;
	if (is_separator(info.separator) == 1)
		ft_prefonction_router(info.next, env, utils);
	else
		check_to_next(*info.next, env, utils);
}

int		ft_next_is_pipe(t_parsing info, char **env, t_utils *utils, int flag)
{
	if (is_separator(info.separator) == 0 || is_separator(info.separator) == 1)
		return (flag);
	if (is_separator(info.separator) == 2)
		return (1);
	else
		flag = ft_next_is_pipe(*info.next, env, utils, flag);
	return (flag);
}

void	ft_pipe_settings(t_utils *utils)
{
	pipe(utils->fdout);
	if (utils->savefd == -1)
		utils->savefd = dup(1);
	dup2(utils->fdout[1], 1);
	close(utils->fdout[1]);
}
