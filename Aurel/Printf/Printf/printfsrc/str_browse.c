/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_browse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:02:46 by awery             #+#    #+#             */
/*   Updated: 2020/12/19 17:49:01 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

int	char_is_about_conv_indicator(char c)
{
	if (c == 'c')
		return (0);
	if (c == 's')
		return (0);
	if (c == 'p')
		return (0);
	if (c == 'd')
		return (0);
	if (c == 'i')
		return (0);
	if (c == 'u')
		return (0);
	if (c == 'x')
		return (0);
	if (c == 'X')
		return (0);
	if (c == '%')
		return (0);
	return (1);
}

int char_is_about_flag(const char *str, int i, int *flag, int *size)
{
	if (str[i] == '-')
	{
		*flag = (*flag) | (e_flagptf_minus);
		return (1);
	}
	if (str[i] == '0')
	{
		*flag = (*flag) | (e_flagptf_zero);
		return (1);
	}
	if (str[i] == '*')
	{
		if (((*flag) | (e_flagptf_point)) == *flag)
			*flag = (*flag) | (e_flagptf_star_postpoint);
		else
			*flag = (*flag) | (e_flagptf_star);
		return (1);
	}
	if (str[i] == '.')
	{
		*flag = (*flag) | (e_flagptf_point);
		size[1] = 0;
		return (1);
	}
	return (0);
}

int	flag_in_pft(int flag, int flag_to_check)
{
	if (((flag) | (flag_to_check)) == flag)
		return (1);
	else
		return (0);
}

int	ft_rm_flag_ptf(int flag, int flag_to_rm)
{
	int flagfinal;

	flagfinal = 0;
	if (flag_in_pft(flag, e_flagptf_point) &&
			(flag_to_rm != e_flagptf_point))
		flagfinal = (flagfinal) | (e_flagptf_point);
	if (flag_in_pft(flag, e_flagptf_minus) &&
			(flag_to_rm != e_flagptf_minus))
		flagfinal = (flagfinal) | (e_flagptf_minus);
	if (flag_in_pft(flag, e_flagptf_zero) &&
			(flag_to_rm != e_flagptf_zero))
		flagfinal = (flagfinal) | (e_flagptf_zero);
	if (flag_in_pft(flag, e_flagptf_star_postpoint) &&
			(flag_to_rm != e_flagptf_star_postpoint))
		flagfinal = (flagfinal) | (e_flagptf_star_postpoint);
	if (flag_in_pft(flag, e_flagptf_star) &&
			(flag_to_rm != e_flagptf_star))
		flagfinal = (flagfinal) | (e_flagptf_star);
	if (flag_in_pft(flag, e_flagptf_size) &&
			(flag_to_rm != e_flagptf_size))
		flagfinal = (flagfinal) | (e_flagptf_size);
	if (flag_in_pft(flag, e_flagptf_size_postpoint) &&
			(flag_to_rm != e_flagptf_size_postpoint))
		flagfinal = (flagfinal) | (e_flagptf_size_postpoint);
	return (flagfinal);
}

int char_is_about_size(const char *str, int i, int *size, int *flag)
{
	int			which_size;
	static int	first_time_point;

	if (str[i] >= '0' && str[i] <= '9')
	{
		if (((*flag) | (e_flagptf_point)) == *flag)
			which_size = 1;
		else
			which_size = 0;
		if (size[which_size] == 0 || (size[which_size] == 1 &&
					first_time_point == 0 && which_size == 1))
		{
			size[which_size] = str[i] - 48;
			if (size[which_size] == 1 && first_time_point == 0 && which_size == 1)
				first_time_point = 1;
			if (size[which_size] == 0)
				first_time_point = 0;
		}
		else
		{
			first_time_point = 0;
			size[which_size] = (size[which_size] * 10) + str[i] - 48;
		}
		return (1);
	}
	return (0);
}
