/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:03:40 by awery             #+#    #+#             */
/*   Updated: 2021/02/13 17:46:05 by Aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int			ft_isspace(char c)
{
	if (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v')
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}

char				*ft_in_base(char *str, char *to_find)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == *to_find)
			return (str + i);
		i++;
	}
	return (0);
}

int					ft_atoi_base(char *str, char *base)
{
	int				sign;
	unsigned int	result;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_in_base(base, str))
	{
		result *= ft_strlen(base);
		result += ft_in_base(base, str) - base;
		str++;
	}
	return (result * sign);
}

static int			ft_final(int nb, char *base_to)
{
	unsigned int	nbr;
	int				len;
	unsigned int	baselen;

	len = 1;
	if (nb < 0)
	{
		nbr = -nb;
		len++;
	}
	else
		nbr = nb;
	baselen = ft_strlen(base_to);
	while (nbr >= baselen)
	{
		nbr /= baselen;
		len++;
	}
	return (len);
}

char				*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*nb_convert;
	int		nb_base_ten;

	if (!ft_basechecker(base_from) || !ft_basechecker(base_to))
		return (0);
	nb_base_ten = ft_atoi_base(nbr, base_from);
	nb_convert = (char *)malloc(sizeof(char) *
			ft_final(nb_base_ten, base_to) + 1);
	ft_putnbr_base(nb_base_ten, base_to, nb_convert);
	nb_convert[ft_final(nb_base_ten, base_to)] = '\0';
	ft_str_rev(nb_convert);
	return (nb_convert);
}
