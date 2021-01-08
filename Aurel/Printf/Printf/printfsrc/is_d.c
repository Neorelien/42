/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 00:10:23 by awery             #+#    #+#             */
/*   Updated: 2020/12/22 18:31:05 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

static void	ft_flag_point_support(int *size, char *arg_str,
		int *arg_value, int i)
{
	if (arg_value[0] < 0 && (arg_str++) && (arg_value[1]--))
		ft_putchar_fd('-', 1);
	while ((size[1] - i - arg_value[1]) > 0 && ((i++) || (1)))
		ft_putchar_fd('0', 1);
	ft_putstr_fd(arg_str, 1, 100);
	if (arg_value[0] < 0)
		arg_value[1]++;
	while ((size[0] - i++ - arg_value[1]) > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_flag_point(int flag, int *size, char *arg_str, int *arg_value)
{
	int i;

	i = 0;
	if (((flag) | (e_flagptf_minus)) == flag)
	{
		ft_flag_point_support(size, arg_str, arg_value, i);
		return ;
	}
	if (arg_value[0] < 0 && ((size[0]--) || 1))
		arg_value[1]--;
	if (size[1] > arg_value[1])
		while ((size[0] - i++ - size[1]) > 0)
			ft_putchar_fd(' ', 1);
	else
		while ((size[0] - i++ - arg_value[1]) > 0)
			ft_putchar_fd(' ', 1);
	if (arg_value[0] < 0 && (arg_str++))
		ft_putchar_fd('-', 1);
	while ((size[1]-- - arg_value[1]) > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(arg_str, 1, 100);
}

static void	ft_is_zero_flag(int *arg_value, char *arg_str, int *size)
{
	if (arg_value[0] < 0)
		arg_str++;
	if (arg_value[0] < 0)
		ft_putchar_fd('-', 1);
	while (size[0]-- - arg_value[1] > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(arg_str, 1, 100);
}

static void	ft_just_size(int flag, char *arg_str, int *arg_value, int *size)
{
	if (((flag) | (e_flagptf_minus)) == flag)
	{
		if (arg_value[0] < 0 && (arg_str++))
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg_str, 1, 100);
		while (size[0]-- - arg_value[1] > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (((flag) | (e_flagptf_zero)) == flag)
		ft_is_zero_flag(arg_value, arg_str, size);
	else
	{
		if (arg_value[0] < 0)
			arg_str++;
		while (size[0]-- - arg_value[1] > 0)
			ft_putchar_fd(' ', 1);
		if (arg_value[0] < 0)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg_str, 1, 100);
	}
}

void		ft_is_d_ptf(int flag, int *size, va_list *arg)
{
	int		arg_value[2];
	char	*arg_str;

	arg_value[0] = (int)va_arg(*arg, int);
	arg_str = ft_itoa_sign(arg_value[0]);
	if (arg_value[0] == 0 &&
			((flag) | (e_flagptf_point)) == flag && size[1] == 0)
		arg_str[0] = ' ';
	arg_value[1] = ft_strlen(arg_str);
	if (arg_value[0] == 0 && (((flag) | (e_flagptf_point)) == flag) &&
			size[1] == 0 && size[0] == 0)
	{
		free(arg_str);
		return ;
	}
	else if (size[0] == 0 && size[1] == 0 &&
			(((flag) | (e_flagptf_point)) != flag))
		ft_putstr_fd(arg_str, 1, 100);
	else if (((flag) | (e_flagptf_point)) == flag)
		ft_flag_point(flag, size, arg_str, arg_value);
	else
		ft_just_size(flag, arg_str, arg_value, size);
	free(arg_str);
}