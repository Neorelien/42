/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:00:21 by awery             #+#    #+#             */
/*   Updated: 2021/01/08 19:19:11 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

void	ft_ajust_size_ptf(int *flag, int *size, va_list *arg)
{
	int size_value;

	if (((*flag) | (e_flagptf_star)) == *flag)
	{
		size_value = (int)va_arg(*arg, int);
		if (size_value < 0)
		{
			size[0] = -1 * size_value;
			*flag = (*flag) | (e_flagptf_minus);
		}
		else
			size[0] = size_value;
	}
	if (((*flag) | (e_flagptf_star_postpoint)) == *flag)
	{
		size_value = (int)va_arg(*arg, int);
		if (size_value < 0)
		{
			*flag = ft_rm_flag_ptf(*flag, e_flagptf_point);
			size[1] = 0;
		}
		else
			size[1] = size_value;
	}
}

int		ft_manage_types_ptf(char c, int *size, int flag, va_list *arg)
{
	if (c == 'c')
		ft_is_c_ptf(flag, size, arg);
	if (c == 's')
		ft_is_s_ptf(flag, size, arg);
	if (c == 'p')
		ft_is_p_ptf(flag, size, arg);
	if (c == 'd' || c == 'i')
		ft_is_d_ptf(flag, size, arg);
	if (c == 'u')
		ft_is_u_ptf(flag, size, arg);
	if (c == 'x' || c == 'X')
		ft_is_x_ptf(flag, size, arg, c);
	if (c == '%')
		ft_is_pourcent_ptf(flag, size);
	return (1);
}

int		convertion_indicator(const char *str, int *i, va_list *arg)
{
	int flag;
	int size[2];

	size[0] = 0;
	size[1] = 0;
	flag = 0;
	(*i)++;
	while (char_is_about_conv_indicator(str[*i]))
	{
		while (char_is_about_flag(str, *i, &flag, size))
			(*i)++;
		while (char_is_about_size(str, *i, size, &flag))
			(*i)++;
		if (char_error_ptf(str[*i]))
			return (0);
	}
	ft_ajust_size_ptf(&flag, size, arg);
	if (!(ft_manage_types_ptf(str[*i], size, flag, arg)))
		return (0);
	return (1);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	va_list arg;

	char_displayed = 0;
	i = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (!(convertion_indicator(str, &i, &arg)))
				return (-1);
			else
				i++;
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			i++;
		}
	}
	va_end(arg);
	return(char_displayed);
}
