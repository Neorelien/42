/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:51:40 by cmoyal            #+#    #+#             */
/*   Updated: 2020/12/07 12:13:18 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_len(int nb)
{
	unsigned int	nbr;
	int				len;

	len = 0;
	if (nb < 0)
	{
		nbr = -nb;
		len++;
	}
	else
		nbr = nb;
	while (nbr >= 10)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

void		ft_putnbr(int nbr, char *nb_convert, int sign)
{
	unsigned int	nb;

	if (nbr < 0)
	{
		nb = nbr * -1;
		sign = -1;
	}
	else
		nb = nbr;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, nb_convert + 1, sign);
	}
	else if (sign == -1)
		*(nb_convert + 1) = '-';
	*nb_convert = nb % 10 + 48;
}

static void	ft_str_rev(char *src)
{
	unsigned int	srclen;
	unsigned int	i;
	char			temp;

	i = 0;
	srclen = ft_strlen(src);
	while (--srclen > i)
	{
		temp = src[i];
		src[i] = src[srclen];
		src[srclen] = temp;
		i++;
	}
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_len(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_putnbr(n, str, 0);
	str[len] = 0;
	ft_str_rev(str);
	return (str);
}
