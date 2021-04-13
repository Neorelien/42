/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:44:44 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/13 13:58:16 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

int		ft_cd_wave(t_parsing info, char ***env, t_cd cd)
{
	chdir(ft_home_dir(*env));
	if (info.data[0][1] == '/' && info.data[0][2] != 0
		&& chdir(info.data[0] + 2) < 0)
	{
		free(cd.oldpath);
		return (ft_error(strerror(errno), info.data[0]));
	}
	return (0);
}

int		ft_cd_second(t_parsing info, char ***env, t_utils *utils, t_cd cd)
{
	if (info.data == NULL)
		chdir(ft_home_dir(*env));
	else if (info.data[0][0] == '~' && (info.data[0][1] == '/'
		|| info.data[0][1] == 0))
		return (ft_cd_wave(info, env, cd));
	else if (info.data[0][0] == '-' && info.data[0][1] == 0)
	{
		if (chdir(utils->oldpwd) < 0)
		{
			free(cd.oldpath);
			return (ft_error(strerror(errno), NULL));
		}
		ft_putstr_fd(utils->oldpwd, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		if (info.data[0][0] != 0 && chdir(info.data[0]) < 0)
		{
			free(cd.oldpath);
			return (ft_error(strerror(errno), info.data[0]));
		}
	}
	return (0);
}

void	ft_free_cd(t_utils *utils, t_cd cd, char ***env)
{
	if (utils->pwd != NULL)
		free(utils->pwd);
	if (utils->oldpwd != NULL)
		free(utils->oldpwd);
	utils->pwd = cd.path;
	utils->oldpwd = cd.oldpath;
	cd.path = ft_strjoin("PWD=", cd.path);
	cd.oldpath = ft_strjoin("OLDPWD=", cd.oldpath);
	add_env_pwd(cd.path, env);
	add_env_pwd(cd.oldpath, env);
	free(cd.path);
	free(cd.oldpath);
}

int		ft_cd(t_parsing info, char ***env, t_utils *utils)
{
	t_cd cd;

	if (ft_next_is_pipe(info, *env, utils, 0) == 1)
		return (0);
	cd.path = NULL;
	cd.oldpath = NULL;
	if ((cd.oldpath = getcwd(cd.path, 0)) == NULL)
		cd.oldpath = ft_strdup(utils->pwd);
	if (ft_doubletab_len(info.data) > 1)
	{
		free(cd.oldpath);
		return (ft_error("cd: Too much args", NULL));
	}
	if (ft_cd_second(info, env, utils, cd) == 1)
		return (1);
	if ((cd.path = getcwd(cd.path, 0)) == NULL)
		cd.path = ft_strjoin_slash(utils->pwd, info.data[0]);
	ft_free_cd(utils, cd, env);
	return (0);
}
