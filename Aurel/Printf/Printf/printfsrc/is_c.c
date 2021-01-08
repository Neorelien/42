/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 23:12:51 by awery             #+#    #+#             */
/*   Updated: 2020/12/22 18:30:33 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

void	ft_is_c_ptf(int flag, int *size, va_list *arg)
{
	unsigned char	arg_value;

	arg_value = (unsigned char)va_arg(*arg, int);
	if (size[0] == 0)
		ft_putchar_fd(arg_value, 1);
	else if (size[0] > 0 && (((flag) | (e_flagptf_minus)) == flag))
	{
		ft_putchar_fd(arg_value, 1);
		while (size[0]-- - 1)
			ft_putchar_fd(' ', 1);
	}
	else if (size[0] > 0)
	{
		while (size[0]-- - 1)
			ft_putchar_fd(' ', 1);
		ft_putchar_fd(arg_value, 1);
	}
}
