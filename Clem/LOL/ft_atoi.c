/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:58:47 by awery             #+#    #+#             */
/*   Updated: 2020/11/19 20:12:01 by awery            ###   ########.fr       */
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
	convert(&result, str);
	return (result * sign);
}
