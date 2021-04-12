/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:03:05 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/12 16:50:37 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		ft_sep_second(t_parsing info, int sep)
{
	int fd;

	if (sep == 4)
	{
		fd = open(info.next->objet, O_RDONLY);
		if (fd < 0)
			return (ft_error(strerror(errno), info.next->objet));
		close(fd);
		return (ft_sep(*info.next));
	}
	else
	{
		fd = open(info.next->objet, O_RDWR | O_APPEND | O_CREAT, 0644
			| O_DIRECTORY);
		if (fd < 0)
			return (ft_error(strerror(errno), info.next->objet));
		close(fd);
		return (ft_sep(*info.next));
	}
}

int		ft_sep(t_parsing info)
{
	int sep;
	int fd;

	if ((sep = is_separator(info.separator)) == 0 || sep == 1)
		return (0);
	else if (sep == 2)
		return (0);
	else if (sep == 3)
	{
		fd = open(info.next->objet, O_WRONLY | O_TRUNC | O_CREAT, 0644
			| O_DIRECTORY);
		if (fd < 0)
			return (ft_error(strerror(errno), info.next->objet));
		close(fd);
		return (ft_sep(*info.next));
	}
	else if (sep == 4 || sep == 5)
	{
		return (ft_sep_second(info, sep));
	}
	return (0);
}

int		is_separator_parsing(char *str, int i)
{
	if (i > 0)
	{
		if (str[i] == ';' && str[i - 1] != 92)
			return (1);
		if (str[i] == '|' && str[i - 1] != 92)
			return (2);
		if (str[i] == '<' && str[i - 1] != 92)
			return (4);
		if (str[i] == '>' && str[i + 1] == '>' && str[i - 1] != 92)
			return (5);
		if (str[i] == '>' && str[i - 1] != 92)
			return (3);
		return (0);
	}
	if (str[i] == ';')
		return (1);
	if (str[i] == '|')
		return (2);
	if (str[i] == '>')
		return (3);
	if (str[i] == '<')
		return (4);
	if (str[i] == '>' && str[i + 1] == '>')
		return (5);
	return (0);
}

int		is_separator(char *str)
{
	if (str[0] == ';' && str[1] == 0)
		return (1);
	if (str[0] == '|' && str[1] == 0)
		return (2);
	if (str[0] == '>' && str[1] == 0)
		return (3);
	if (str[0] == '<' && str[1] == 0)
		return (4);
	if (str[0] == '>' && str[1] == '>' && str[2] == 0)
		return (5);
	return (0);
}
