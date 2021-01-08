/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 14:08:09 by awery             #+#    #+#             */
/*   Updated: 2020/12/22 18:24:08 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_utils.h"

int	char_error_ptf(char c)
{
	if (c == '-' || c == '.')
		return (0);
	if (c >= '0' && c <= '9')
		return (0);
	if (c == '*')
		return (0);
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
