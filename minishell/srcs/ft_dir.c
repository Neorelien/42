/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:57:18 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/06 16:57:18 by cmoyal           ###   ########.fr       */
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

char	*ft_display_rep(char **env, t_utils utils)
{
	char	*path;
	int		size;
	char	*temp;
	
	path = NULL;
	temp = NULL;
	if ((path = getcwd(path, 0)) == NULL)
		path = ft_strdup(utils.pwd);
	temp = path;
	size = (int)ft_strlen(path);
	if (ft_strncmp(path, ft_home_dir(env), 4096) == 0)
	{
		size = 2;
		path = "/~";
	}
	while (size >= 0 && path[size] != '/')
		size--;
	path += size + 1;
	path = ft_strdup(path);
	free(temp);
	temp = path;
	path = ft_strjoin(path, " ");
	free(temp);
	return (path);
}

static void    add_env_pwd(char *str, char ***env)                         
{                                                                               
    int     len;                                                                
    char    **tmp;                                                              
                                                                                
    len = ft_doubletab_len(*env);                                               
    tmp = *env;                                                                 
    *env = malloc(sizeof(char*) * (len + 2));                                   
    *env = recopy_data(*env, tmp, 1);                                              
    free(tmp);                                                                  
    if (env_in_env(*env, str))                                     
        ;                                                                       
    else                                                                        
    {                                                                           
        env[0][len] = ft_strdup(str);                              
        env[0][len + 1] = NULL;                                                 
    }                                                                           
}
char *ft_strjoin_slash(char *str, char *str_bis)
{
	char *temp;
	char *result;

	temp = ft_strjoin(str, "/");
	result = ft_strjoin(temp, str_bis);
	free(temp);
	return (result);
	
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

int ft_pwd(t_parsing info,char ***env, t_utils *utils)
{
	char *path;
	char *temp;

	(void)env;
	path = NULL;
	temp = NULL;
	if (ft_doubletab_len(info.data) > 0)
		return (ft_error("pwd: too many arguments", NULL));
	if ((path = getcwd(path, 0)) == NULL)
		path = utils->pwd;
	else
		temp = path;
	ft_putstr_fd(path, 1);
	ft_putchar_fd('\n', 1);
	if (temp != NULL)
		free(temp);
	return (0);
}
