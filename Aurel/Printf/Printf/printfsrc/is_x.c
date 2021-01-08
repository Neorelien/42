/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 00:10:23 by awery             #+#    #+#             */
/*   Updated: 2021/01/08 18:20:48 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

static void ft_flag_point_support(int *size, char *arg_str, unsigned int *arg_value, int i)
{
	int	arg_size;

	arg_size = arg_value[1];
	if (arg_value[0] < 0 && (arg_str++) && (arg_size--))
		ft_putchar_fd('-', 1);
	while ((size[1] - i - arg_size) > 0 && ((i++) || (1)))
		ft_putchar_fd('0', 1);
	ft_putstr_fd(arg_str, 1, 100);
	if (arg_value[0] < 0)
		arg_size++;
	while ((size[0] - i++ - arg_size) > 0)
		ft_putchar_fd(' ', 1);
}

static void	ft_flag_point(int flag, int *size, char *arg_str, unsigned int *arg_value)
{
	int i;
	int	arg_size;

	arg_size = arg_value[1];
	i = 0;
	if (((flag) | (e_flagptf_minus)) == flag)
	{
		ft_flag_point_support(size, arg_str, arg_value, i);
		return;
	}
	if (arg_value[0] < 0 && ((size[0]--) || 1))
		arg_size--;
	if (size[1] > arg_size)
	{
		while ((size[0] - i++ - size[1]) > 0)
			ft_putchar_fd(' ', 1);
	}
	else
	{
		while ((size[0] - i++ - arg_size) > 0)
			ft_putchar_fd(' ', 1);
	}
	if (arg_value[0] < 0 && (arg_str++))
		ft_putchar_fd('-', 1);
	while ((size[1]-- - arg_size) > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(arg_str, 1, 100);
}

static void	ft_is_zero_flag(unsigned int *arg_value, char *arg_str, int *size)
{
	int arg_size;

	arg_size = arg_value[1];
	if (arg_value[0] < 0)
		arg_str++;
	if (arg_value[0] < 0)
		ft_putchar_fd('-', 1);
	while (size[0]-- - arg_size > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(arg_str, 1, 100);
}

static void	ft_just_size(int flag, char *arg_str, unsigned int *arg_value, int *size)
{
	int	arg_size;

	arg_size = arg_value[1];
	if (((flag) | (e_flagptf_minus)) == flag)
	{
		if (arg_value[0] < 0 && (arg_str++))
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg_str, 1, 100);
		while (size[0]-- - arg_size > 0)
			ft_putchar_fd(' ', 1);
	}
	else if (((flag) | (e_flagptf_zero)) == flag)
		ft_is_zero_flag(arg_value, arg_str, size);
	else
	{
		if (arg_value[0] < 0)
			arg_str++;
		while (size[0]-- - arg_size > 0)
			ft_putchar_fd(' ', 1);
		if (arg_value[0] < 0)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg_str, 1, 100);
	}
}

void		ft_is_x_ptf(int flag, int *size, va_list *arg, char conv)
{
	unsigned int		arg_value[2];
	char				*arg_str;
	char				*temp;
	int					i;

	i = 0;
	arg_value[0] = (unsigned int)va_arg(*arg, unsigned int);
	temp = ft_itoa(arg_value[0]);
	if (conv == 'x')
		arg_str = ft_convert_base(temp, "0123456789", "0123456789abcdef");
	else
		arg_str = ft_convert_base(temp, "0123456789", "0123456789ABCDEF");
	free(temp);
	if (arg_value[0] == 0 && ((flag) | (e_flagptf_point)) == flag && size[1] == 0)
		arg_str[0] = ' ';
	arg_value[1] = ft_strlen(arg_str);
	if (arg_value[0] == 0 && (((flag) | (e_flagptf_point)) == flag) &&
			size[1] == 0 && size[0] == 0)
	{
		free(arg_str);
		return ;
	}
	else if (size[0] == 0 && size[1] == 0 && (((flag) | (e_flagptf_point)) != flag))
	{
		if (arg_value[0] < 0)
			ft_putchar_fd('-', 1);
		ft_putstr_fd(arg_str, 1, arg_value[1]);
	}
	else if (((flag) | (e_flagptf_point)) == flag )
		ft_flag_point(flag, size, arg_str, arg_value);
	else
		ft_just_size(flag, arg_str, arg_value, size);
	free(arg_str);
}
