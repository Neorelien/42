/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:44:47 by cmoyal            #+#    #+#             */
/*   Updated: 2020/11/19 13:22:47 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

int		ft_isnumber(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int		ft_plusoumoins(char c)
{
	if (c == '+')
		return (1);
	else if (c == '-')
		return (-1);
	else
		return (0);
}

int		ft_atoi(const char *nptr)
{
	int		sign;
	int		result;
	char	*str;

	str = (char *)nptr;
	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (ft_plusoumoins(*str))
		sign *= ft_plusoumoins(*str++);
	if (sign < 0 && ft_isnumber(*str))
	{
		result = *str++ - 48;
		result *= sign;
		while (ft_isnumber(*str))
			result = result * 10 - (*str++ - 48);
	}
	while (ft_isnumber(*str))
		result = result * 10 + (*str++ - 48);
	return (result);
}
