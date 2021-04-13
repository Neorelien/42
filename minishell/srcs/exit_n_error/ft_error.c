/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 16:53:52 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/13 14:10:45 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

int	ft_error(char *str, char *strbis)
{
	ft_putstr_fd(str, 2);
	if (strbis != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strbis, 2);
	}
	ft_putchar_fd('\n', 2);
	return (1);
}
