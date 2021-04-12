/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 14:44:44 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/09 14:54:04 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_cd(t_parsing info, char ***env, t_utils *utils)
{
	char *path;
	char *oldpath;

	if (ft_next_is_pipe(info, *env, utils, 0) == 1)
	{
		ft_putstr_fd(utils->oldpwd, 1);
		ft_putchar_fd('\n', 1);
		return (0);
	}
	path = NULL;
	oldpath = NULL;
	if ((oldpath = getcwd(path, 0)) == NULL)
		oldpath = ft_strdup(utils->pwd);
	if (ft_doubletab_len(info.data) > 1)
	{
		free(oldpath);
		return (ft_error("cd: Too much args", NULL));
	}
	if (info.data == NULL)
		chdir(ft_home_dir(*env));
	else if (info.data[0][0] == '~' && (info.data[0][0] == '/' || info.data[0][0] == 0))
	{
		chdir(ft_home_dir(*env));
		if (chdir(info.data[0] + 2) < 0)
		{
			free(oldpath);
			return (ft_error(strerror(errno), info.data[0]));
		}
	}
	else if (info.data[0][0] == '-' && info.data[0][1] == 0)
	{
		if (chdir(utils->oldpwd) < 0)
		{
			ft_error(strerror(errno), NULL);
			free(oldpath);
			return (1);
		}
		ft_putstr_fd(utils->oldpwd, 1);
		ft_putchar_fd('\n', 1);
	}
	else if (info.data[0][0] == 0)
		;
	else
	{
		if (chdir(info.data[0]) < 0)
		{
			free(oldpath);
			return (ft_error(strerror(errno), info.data[0]));
		}
	}
	if ((path = getcwd(path, 0)) == NULL)
		path = ft_strjoin_slash(utils->pwd, info.data[0]);
	if (utils->pwd != NULL)
		free(utils->pwd);
	if (utils->oldpwd != NULL)
		free(utils->oldpwd);
	utils->pwd = path;
	utils->oldpwd = oldpath;
	path = ft_strjoin("PWD=", path);
	oldpath = ft_strjoin("OLDPWD=", oldpath);
	add_env_pwd(path, env);
	add_env_pwd(oldpath, env);
	free(path);
	free(oldpath);
	return (0);
}

