/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:20:01 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/09 13:58:11 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

char	*ft_read_fd(t_utils *utils)
{
	int		ret;
	char	buff[2];
	char	*result;
	char	*temp;

	ret = 1;
	result = ft_strdup("");
	while (read(utils->fdout[0], buff, 1))
	{
		buff[1] = 0;
		temp = ft_strjoin(result, buff);
		free(result);
		result = temp;
	}
	return (result);
}

void	ft_redir_sec(t_parsing info, char **env, t_utils *utils, t_redir redir)
{
	if (redir.sep == 2)
	{
		if (utils->savefd == -1)
			ft_pipe_settings(utils);
	}
	else if (redir.sep == 4)
	{
		redir.fd = open(info.next->objet, O_RDONLY);
		utils->savefdout = dup(0);
		dup2(redir.fd, 0);
		close(redir.fd);
		ft_redir(*info.next, env, utils);
	}
	else if (redir.sep == 5)
	{
		redir.fd = open(info.next->objet, O_RDWR | O_APPEND | O_CREAT, 0644
			| O_DIRECTORY);
		if (redir.fd < 0)
			ft_error(strerror(errno), info.next->objet);
		utils->savefd = dup(utils->redir);
		dup2(redir.fd, utils->redir);
		close(redir.fd);
		ft_redir(*info.next, env, utils);
	}
}

void	ft_redir(t_parsing info, char **env, t_utils *utils)
{
	t_redir redir;

	if (utils->fdout[0] != 0)
	{
		redir.result = ft_read_fd(utils);
		pipe(utils->fdin);
		write(utils->fdin[1], redir.result, ft_strlen(redir.result));
		free(redir.result);
		close(utils->fdout[0]);
		utils->fdout[0] = 0;
	}
	if ((redir.sep = is_separator(info.separator)) == 3)
	{
		redir.fd = open(info.next->objet, O_WRONLY | O_CREAT, 0644
			| O_DIRECTORY);
		if (redir.fd < 0)
			ft_error(strerror(errno), info.next->objet);
		if (utils->savefd == -1)
			utils->savefd = dup(utils->redir);
		dup2(redir.fd, utils->redir);
		close(redir.fd);
		ft_redir(*info.next, env, utils);
	}
	ft_redir_sec(info, env, utils, redir);
}
