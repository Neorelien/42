/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:57:18 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/05 16:10:46 by cmoyal           ###   ########.fr       */
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

int	ft_display_rep(char **env)
{
	char	*path;
	int		size;
	char	*temp;

	path = NULL;
	path = getcwd(path, 0);
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

int ft_cd(t_parsing info, char **env)
{
	if (ft_doubletab_len(info.data) > 1)
		return (ft_error("cd: string not in pwd: ", info.data[0]));
	if ((write_with_separator(info)) <= 0)
		return (ft_error("zsh: is a directory: ", info.next->objet));	
	if (info.data == NULL)
		chdir(ft_home_dir(env));
	else if (info.data[0][0] == '~')
	{
		chdir(ft_home_dir(env));
		chdir(info.data[0] + 2);
	}
	else
		chdir(info.data[0]);
	return (1);
}

int ft_pwd(t_parsing info)
{
	int fd;
	char *path;

	path = NULL;
	if (ft_doubletab_len(info.data) > 0)
		return (-1);
	if ((fd = write_with_separator(info)) <= 0)
		return (-1);
	ft_putstr_fd(getcwd(path, 0), fd);
	ft_putchar_fd('\n', fd);
	if (path != NULL)
		free(path);
	return (1);	
}
