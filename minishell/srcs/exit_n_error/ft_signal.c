/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 17:03:24 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/13 13:58:59 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

void	handler_next(int sign)
{
	if (g_sig.pid == -1)
	{
		(void)sign;
		ft_print_prefix(0, 1, NULL, NULL);
	}
	else
		ft_putstr_fd("\n", 1);
}

void	handler_quit(int sign)
{
	if (g_sig.pid != -1)
		printf("Quit: %d\n", sign);
}
