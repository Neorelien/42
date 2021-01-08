/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 12:12:30 by awery             #+#    #+#             */
/*   Updated: 2021/01/05 16:37:28 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
#define PRINTF_UTILS_H

#include "libc.h"
#include <stdarg.h>
#include "../Libft/libft.h"

enum	e_flagptf
{
	e_flagptf_minus = 1,
	e_flagptf_zero = 2,
	e_flagptf_star = 4,
	e_flagptf_star_postpoint = 8,
	e_flagptf_point = 16,
	e_flagptf_size = 32,
	e_flagptf_size_postpoint = 64,
	e_flagptf_neg_aftpoint = 128
};

int		ft_printf(const char *str, ...);
int		char_is_about_size(const char *str, int i, int *size, int *flag);
int		char_is_about_flag(const char *str, int i, int *flag, int *size);
int		char_is_about_conv_indicator(char c);
int		char_error_ptf(char c);
void	ft_is_c_ptf(int flag, int *size, va_list *arg);
void	ft_is_d_ptf(int flag, int *size, va_list *arg);
void	ft_is_s_ptf(int flag, int *size, va_list *arg);
int		ft_rm_flag_ptf(int flag, int flag_to_rm);
void	ft_is_p_ptf(int flag, int *size, va_list *arg);
void	ft_is_u_ptf(int flag, int *size, va_list *arg);
void	ft_is_x_ptf(int flag, int *size, va_list *arg, char conv);
void	ft_is_pourcent_ptf(int flag, int *size);

#endif
