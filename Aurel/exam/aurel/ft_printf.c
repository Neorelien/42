#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

typedef	struct		s_utils
{
	int	nb_print;
	int	precision;
	int	champ;
}					t_utils;

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_nb_len(int nb)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int		ft_hex_len(unsigned int nb)
{
	int i;

	i = 1;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb >= 16)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

void	put_int(int nb, t_utils *uti)
{
	char c;
	if (nb >= 10)
	{
		c = (nb % 10) + 48;
		put_int(nb / 10, uti);
		uti->nb_print++;
		write(1, &c, 1);
	}
	else
	{
		uti->nb_print++;
		c = (nb + 48);
		write(1, &c, 1);
	}
}

void	put_hex(unsigned int nb, t_utils *uti)
{
	char c;
	char base[17] = "0123456789abcdef";

	if (nb > 16)
	{
		put_hex(nb / 16, uti);
		uti->nb_print++;
		write(1, &base[nb % 16], 1);
	}
	else
	{
		uti->nb_print++;
		write(1, &base[nb], 1);
	}
}

void	put_char(char *str, int res_l, t_utils *uti)
{
	int i;
	i= 0;
	while (str[i] && i < res_l)
	{
		uti->nb_print++;
		write(1, &str[i++], 1);
	}
}

void	is_d(t_utils *uti, va_list *ap)
{
	int	nb;
	char *res;
	int res_l;
	int temp;
	int i;

	i = 0;
	nb = va_arg(*ap, int);
	if ((uti->precision == -1 || uti->precision == 0) && nb == 0)
		return ;
	res_l = ft_nb_len(nb);
	temp = res_l;
	if (res_l < uti->precision)
	{
		if (nb < 0)
			uti->champ--;
		res_l = uti->precision;
	}
	while (uti->champ > res_l)
	{
		write(1, " ", 1);
		uti->nb_print++;
		uti->champ--;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		uti->nb_print++;
		temp--;
		nb *= -1;
	}
	while(res_l > temp)
	{
		write(1, "0", 1);
		uti->nb_print++;
		res_l--;
	}
	put_int(nb, uti);
}

void	is_x(t_utils *uti, va_list *ap)
{
	unsigned int	nb;
	int res_l;
	int temp;
	int i;

	i = 0;
	nb = (unsigned int)va_arg(*ap, unsigned int);
	if ((uti->precision == -1 || uti->precision == 0) && nb == 0)
		return ;
	res_l = ft_hex_len(nb);
	temp = res_l;
	if (res_l < uti->precision)
		res_l = uti->precision;
	while (uti->champ > res_l)
	{
		write(1, " ", 1);
		uti->nb_print++;
		uti->champ--;
	}
	while(res_l > temp)
	{
		write(1, "0", 1);
		uti->nb_print++;
		res_l--;
	}
	put_hex(nb, uti);
}

void	is_s(t_utils *uti, va_list *ap)
{
	char *str;
	int res_l;
	int temp;
	int i;

	i = 0;
	str = (char*)va_arg(*ap, char*);
	if (str == NULL)
	{
		put_char("(null)", 10, uti);
		return ;
	}
	res_l = ft_strlen(str);
	temp = res_l;
	if (res_l > uti->precision && uti->precision != -1)
		res_l = uti->precision;
	while (uti->champ > res_l)
	{
		write(1, " ", 1);
		uti->nb_print++;
		uti->champ--;
	}
	put_char(str, res_l, uti);
}


int		ft_printf(const char *str, ... )
{
	int		i;
	t_utils uti;
	va_list ap;

	va_start(ap, str);
	i = 0;
	uti.nb_print = 0;
	while (str[i])
	{
		uti.precision = -1;
		uti.champ = -1;
		if (str[i] == '%')
		{
			i++;
			while (str[i] >= '0' && str[i] <= '9')
			{
				if (uti.champ == -1)
					uti.champ = str[i] - 48;
				else
					uti.champ = uti.champ * 10 + str[i] - 48;
				i++;
			}
			if (str[i] == '.')
			{
				i++;
				if (str[i] == '-')
				{
					i++;
					while (str[i] >= '0' && str[i] <= '9')
						i++;
				}
				else
				{
					while (str[i] >= '0' && str[i] <= '9')
					{
						if (uti.precision == -1)
							uti.precision = str[i] - 48;
						else
							uti.precision = uti.precision * 10 + str[i] - 48;
						i++;
					}
				}
			}
			if (str[i] == 'd')
			{
				is_d(&uti, &ap);
				i++;
			}
			if (str[i] == 'x')
			{
				is_x(&uti, &ap);
				i++;
			}
			if (str[i] == 's')
			{
				is_s(&uti, &ap);
				i++;
			}
		}
		else
		{
			while (str[i] != '%' && str[i])
			{
				write(1, &str[i], 1);
				uti.nb_print++;
				i++;
			}
		}
	}
	va_end(ap);
	return (uti.nb_print);
}
