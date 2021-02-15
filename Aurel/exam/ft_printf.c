#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#define ABS(x) ((x > 0) ? x : -x)
#define MIN(x, y) ((x > y) ? y : x)
#define MAX(x, y) ((x > y) ? x : y)

typedef struct s_flags
{
	int flag_dot;
	int flag_digit;
	char format;
}	t_flags;

int	ft_count(int nb)
{
	static int count;
	if (nb == 2)
		count = 0;
	if (nb == 1)
		count++;
	return (count);
}

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_putchar(char c)
{		
	write(1, &c, 1);
	ft_count(1);
}

void	ft_putnbr(int nbr)
{
	unsigned int	nb;

	nb = ABS(nbr);
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int ft_hexlen(unsigned int nbr)
{
	int i;
	i = 1;
	while (nbr > 15)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

void ft_puthex(unsigned int nbr, char *base)
{	
	unsigned int	i;
	char 		*hexa;
	
	if (!(hexa = malloc(sizeof(char) * (ft_hexlen(nbr) + 1))))
		return;
	i = 0;
	while (nbr > 15)
	{
		hexa[i++] = base[nbr % 16];
		nbr /= 16;
	}
	hexa[i] = base[nbr % 16];
	while (i > 0)
		ft_putchar(hexa[i--]);
	ft_putchar(hexa[i]);
	free(hexa);
}

int	ft_nblen(int nbr, int moins)
{
	int i;
	unsigned int nb;
	nb = ABS(nbr);
	if (nbr >= 0 || moins == 0)
		i = 1;
	else
		i = 2;	
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

void	ft_putint(int nb, t_flags flags)
{
	if (flags.flag_dot == 0 && nb == 0)
	{
		while (flags.flag_digit - MAX(flags.flag_dot, 0) > 0)
		{
			ft_putchar(' ');
			flags.flag_digit--;
		}
		return;
	}
	if (nb < 0)
		flags.flag_dot++;
	while (flags.flag_digit - MAX(flags.flag_dot, ft_nblen(nb, 1)) > 0)
	{
		ft_putchar(' ');
		flags.flag_digit--;
	}	
	if (nb < 0)
	{
		ft_putchar('-');
		flags.flag_dot--;
	}
	while (flags.flag_dot - ft_nblen(nb, 0) > 0)
	{
		ft_putchar('0');
		flags.flag_dot--;
	}
	ft_putnbr(nb);
}

void	ft_putstring(char *str, t_flags flags)
{
	if (str == NULL)
		str = "(null)";
	if (flags.flag_dot == -1)
	{
		while (flags.flag_digit - ft_strlen(str) > 0)
		{
			ft_putchar(' ');
			flags.flag_digit--;
		}
		while (*str)
			ft_putchar(*str++);
		return;
	}
	while (flags.flag_digit - MIN(ft_strlen(str), flags.flag_dot) > 0)
	{
		ft_putchar(' ');
		flags.flag_digit--;
	}
	while (*str && flags.flag_dot > 0)
	{
		ft_putchar(*str++);
		flags.flag_dot--;
	}
}

void ft_puthexadecimal(unsigned int nb, t_flags flags)
{
	if (flags.flag_dot == 0 && nb == 0)
	{
		while (flags.flag_digit - MAX(flags.flag_dot, 0) > 0)
		{
			ft_putchar(' ');
			flags.flag_digit--;
		}
		return;
	}
	while (flags.flag_digit - MAX(flags.flag_dot, ft_hexlen(nb)) > 0)
	{
		ft_putchar(' ');
		flags.flag_digit--;
	}
	while (flags.flag_dot - ft_hexlen(nb) > 0)
	{
		ft_putchar('0');
		flags.flag_dot--;
	}
	ft_puthex(nb, "0123456789abcdef");
}


void	print_format(va_list args, t_flags flags)
{
	if (flags.format == 'd')
		ft_putint((int)va_arg(args, int), flags);
	else if (flags.format == 's')
		ft_putstring((char*)va_arg(args, char*), flags);
	else if (flags.format == 'x')
		ft_puthexadecimal((unsigned int)va_arg(args, unsigned int), flags);
}


char *ft_flag_dot(char *format ,t_flags *flags)
{
	if (ft_isdigit(*(format + 1)))
		while (ft_isdigit(*(format + 1)))
		{
			flags->flag_dot = flags->flag_dot * 10 + *(format + 1) - 48;
			format++;
		}
	else
		flags->flag_dot = 0;
	return (format);
}

char	*ft_flag_digit(char *format, t_flags *flags)
{
	
	flags->flag_digit = flags->flag_digit * 10 + *format - 48;
	return (format);
}

void flags_init(t_flags *flags)
{
	flags->flag_dot = -1;
	flags->flag_digit = 0;
}

char	*printage(char *format, va_list args)
{
	t_flags flags;

	flags_init(&flags);
	format++;
	while (*format)
	{
		if (*format == '.')
		{
			flags.flag_dot = 0;
			format = ft_flag_dot(format, &flags);
		}
		else if (ft_isdigit(*format))
			format = ft_flag_digit(format, &flags);
		else if (*format == 'x' || *format == 's' || *format == 'd')
		{
			flags.format = *format;
			format++;
			break;
		}
		format++;
	}
	print_format(args, flags);
	return (format);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int count;

	ft_count(2);
	if (!format)
		return (0);  
	va_start(args, format);
	while (*format != 0)
		if (*format != '%')
			ft_putchar(*format++);
		else if (*format == '%')
			format = printage((char*)format, args);	
	va_end(args);
	count = ft_count(0);
	return (count);
}
