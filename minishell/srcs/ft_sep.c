/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:03:05 by cmoyal            #+#    #+#             */
/*   Updated: 2021/03/15 14:45:10 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		ft_sep(t_parsing info)
{
	int sep;
	int fd;

	if ((sep = is_separator(info.separator)) == 0 || sep == 1)
		return (1);
    else if (sep == 2)
        return (1);
	else if (sep == 3)
    {
        fd = open(info.next->objet, O_WRONLY | O_CREAT, 0644 | O_DIRECTORY);
        if (fd < 0)
            return (ft_error(strerror(errno), info.next->objet));
		close(fd);
		return (ft_sep(*info.next));
    }
    else if (sep == 4)
        return (ft_sep(*info.next));
    else
    {
        fd = open(info.next->objet, O_RDWR | O_APPEND | O_CREAT, 0644 | O_DIRECTORY);
        if (fd < 0)
            return (ft_error(strerror(errno), info.next->objet));
		close(fd);
        return (ft_sep(*info.next));
    }
	return (1);
}
