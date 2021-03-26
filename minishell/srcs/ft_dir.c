/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:57:18 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/25 15:13:16 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

char *ft_home_dir(char **env)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "HOME=", 4) == 0)
		{
			while (env[i][j] != '=')
				j++;
			return (env[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}

int	ft_display_rep(char **env, t_utils utils)
{
	char	*path;
	int		size;
	char	*temp;
	
	path = NULL;
	if ((path = getcwd(path, 0)) == NULL)
		path = utils.pwd;
	temp = path;
	size = (int)ft_strlen(path);
	if (ft_strncmp(path, ft_home_dir(env), 4096) == 0)
		path = "/~";
	while (size >= 0 && path[size] != '/')
		size--;
	path += size + 1;
	ft_putstr_fd(path, 1);
	ft_putchar_fd(' ', 1);
	if (temp != NULL)
		free(temp);
	return (1);
}

static void    add_env_pwd(char *str, char ***env)                         
{                                                                               
    int     len;                                                                
    char    **tmp;                                                              
                                                                                
    len = ft_doubletab_len(*env);                                               
    tmp = *env;                                                                 
    *env = malloc(sizeof(char*) * (len + 2));                                   
    *env = recopy_data(*env, tmp);                                              
    free(tmp);                                                                  
    if (env_in_env(*env, str))                                     
        ;                                                                       
    else                                                                        
    {                                                                           
        env[0][len] = ft_strdup(str);                              
        env[0][len + 1] = NULL;                                                 
    }                                                                           
}

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
		oldpath = utils->pwd;	
	if (ft_doubletab_len(info.data) > 1)
	{
		free(oldpath);
		return (ft_error("string not in pwd: ", info.data[0]));
	}
	if (info.data == NULL)
		chdir(ft_home_dir(*env));
	else if (info.data[0][0] == '~')
	{
		chdir(ft_home_dir(*env));
		if (chdir(info.data[0] + 2) < 0)
			return (ft_error(strerror(errno), info.data[0]));
	}
	else if (info.data[0][0] == '-')
	{
		if (chdir(utils->oldpwd) == -1)
		{
			ft_error(strerror(errno), NULL);
			return (1);
		}
		ft_putstr_fd(utils->oldpwd, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		if (chdir(info.data[0]) < 0)
			return (ft_error(strerror(errno), info.data[0]));
	}
	path = getcwd(path, 0);
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
	return (0);
}

int ft_pwd(t_parsing info,char ***env, t_utils *utils)
{
	char *path;

	(void)env;
	path = NULL;
	if (ft_doubletab_len(info.data) > 0)
		return (ft_error("pwd: too many arguments", NULL));
	if ((path = getcwd(path, 0)) == NULL)
		path = utils->pwd;
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	if (path != NULL)
		free(path);
	return (0);
}
