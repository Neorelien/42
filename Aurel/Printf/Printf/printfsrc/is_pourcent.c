/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pourcent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 23:12:51 by awery             #+#    #+#             */
/*   Updated: 2020/12/22 18:35:43 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

void	ft_is_pourcent_ptf(int flag, int *size)
{
	unsigned char	arg_value;

	if ((arg_value = '%') == '%' && size[0] == 0)
		ft_putchar_fd(arg_value, 1);
	else if (size[0] > 0 && (((flag) | (e_flagptf_minus)) == flag))
	{
		ft_putchar_fd(arg_value, 1);
		if (((flag) | (e_flagptf_zero)) == flag &&
				((flag) | (e_flagptf_minus)) != flag)
			while (size[0]-- - 1)
				ft_putchar_fd('0', 1);
		else
			while (size[0]-- - 1)
				ft_putchar_fd(' ', 1);
	}
	else if (size[0] > 0)
	{
		if (((flag) | (e_flagptf_zero)) == flag)
			while (size[0]-- - 1)
				ft_putchar_fd('0', 1);
		else
			while (size[0]-- - 1)
				ft_putchar_fd(' ', 1);
		ft_putchar_fd(arg_value, 1);
	}
}
