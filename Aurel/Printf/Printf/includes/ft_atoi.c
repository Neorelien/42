/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:58:47 by awery             #+#    #+#             */
/*   Updated: 2021/01/15 23:37:07 by Aurelien         ###   ########.fr       */
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

void	convert(unsigned int *result, char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i == 0)
			*result = *result + str[i] - 48;
		else
		{
			*result = (*result * 10) + str[i] - 48;
		}
		i++;
	}
}

int		ft_verif_num(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int		ft_atoi(const char *s)
{
	int				sign;
	unsigned int	result;
	char			*str;

	str = (char*)s;
	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (ft_verif_num(str))
		return (-1);
	convert(&result, str);
	return (result * sign);
}
