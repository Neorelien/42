/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:20:01 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/24 18:58:05 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"
char	*ft_read_fd(t_utils *utils)
{
	int ret;
	int i;
	char buff[2];
	char *result;
	char *temp;

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
/*
char	*ft_read_fd(t_utils *utils)
{
	int ret;
	int i;
	char *buff;
	char *result;
	char *temp;

	ret = 1;
	i = 0;
	result = ft_strdup("");
	while (ret)
	{
		if ((ret = get_next_line(utils->fdout[0], &buff)) == -1)
			break ;
		temp = ft_strjoin(result, buff);
		free(result);
		result = temp;
		free(buff);
		i++;
	}
	if (i > 1)
	{
		temp = ft_strjoin(result, "\n");
		free(result);
		result = temp;
	}
	return (result);
}
*/
void	ft_redir(t_parsing info, char **env, t_utils *utils)
{
	int sep;
	int flag_pipe;
	char *result;
	
	if (utils->fdout[0] != 0)
	{
		result = ft_read_fd(utils);
		pipe(utils->fdin);
		write(utils->fdin[1], result, ft_strlen(result));
		close(utils->fdout[0]);
		utils->fdout[0] = 0;
	}
	flag_pipe = ft_next_is_pipe(info, env, utils, 0);
	if ((sep = is_separator(info.separator)) == 0 || sep == 1)
		return ;
    else if (sep == 2)
        ft_pipe_settings(info, env, utils);
	
}
