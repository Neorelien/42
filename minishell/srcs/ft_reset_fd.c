/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:45:39 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/12 16:46:38 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int	reset_fd_one(t_utils *utils)
{
	if (utils->savefd != -1)
	{
		close(utils->redir);
		dup2(utils->savefd, utils->redir);
		close(utils->savefd);
		utils->savefd = -1;
		utils->redir = 1;
		return (1);
	}
	return (0);
}

int	reset_fd_zero(t_utils *utils)
{
	if (utils->savefdout != -1)
	{
		close(0);
		dup2(utils->savefdout, 0);
		close(utils->savefdout);
		utils->savefdout = -1;
		return (1);
	}
	return (0);
}
