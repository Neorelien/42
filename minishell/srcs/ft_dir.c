/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 17:57:18 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/04 18:52:50 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int	ft_display_rep(void)
{
	char	*path;
	int		size;

	path = NULL;
	path = getcwd(path, 0); //malloc need free
	size = (int)ft_strlen(path);
	while (size >= 0 && path[size] != '/')
		size--;
	path += size + 1;
	ft_putstr_fd(path, 1);
	ft_putchar_fd(' ', 1);
	if (path != NULL)
		free(path);
	return (1);
}

int ft_cd(t_parsing info)
{
	if (ft_doubletab_len(info.data) > 1)
		return (-1);
	if ((write_with_separator(info)) <= 0)
		return (-1);
	chdir(info.data[0]);
	return (1);
}

int ft_pwd(t_parsing info)
{
	int fd;
	char *path;

	path = NULL;
	if (ft_doubletab_len(info.data) > 1)
		return (-1);
	if ((fd = write_with_separator(info)) <= 0)
		return (-1);
	ft_putstr_fd(getcwd(path, 0), fd);
	if (path != NULL)
		free(path);
	return (1);
	
}
