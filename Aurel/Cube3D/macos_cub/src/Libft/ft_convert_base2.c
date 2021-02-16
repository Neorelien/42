/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:04:07 by awery             #+#    #+#             */
/*   Updated: 2020/10/28 13:15:29 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

void			ft_putnbr_base(int nbr, char *base, char *nb_convert)
{
	unsigned int	baselen;
	unsigned int	nb;
	int				sign;

	baselen = ft_strlen(base);
	if (nbr < 0)
	{
		nb = nbr * -1;
		sign = -1;
	}
	else
		nb = nbr;
	if (nb >= baselen)
	{
		ft_putnbr_base(nb / baselen, base, nb_convert + 1);
	}
	else
		*(nb_convert + 1) = '-';
	*nb_convert = (base[nb % baselen]);
}

void			ft_str_rev(char *src)
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

int				ft_basechecker(char *base)
{
	int				i;
	int				j;

	i = 0;
	j = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i++])
	{
		if (base[i - 1] == '+' || base[i - 1] == '-')
			return (0);
		else if (base[i - 1] == '\f' || base[i - 1] == '\n')
			return (0);
		else if (base[i - 1] == '\r' || base[i - 1] == '\t')
			return (0);
		else if (base[i - 1] == ' ' || base[i - 1] == '\v')
			return (0);
		j = i;
		while (base[j++])
		{
			if (base[j - 1] == base[i - 1])
				return (0);
		}
	}
	return (1);
}
