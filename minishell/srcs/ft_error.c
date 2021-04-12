/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:53:52 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/12 17:00:47 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int	ft_error(char *str, char *strbis)
{
	ft_putstr_fd(str, 1);
	if (strbis != NULL)
	{
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(strbis, 1);
	}
	ft_putchar_fd('\n', 1);
	return (1);
}
