/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:27:31 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 13:57:30 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int		refresh_screen_supp_1(t_refresh *var)
{
	var->i = 0;
	var->p = 0;
	var->line_old_len = 0;
	return (1);
}

int		refresh_screen_supp_2(int histo, t_refresh *var, char **print)
{
	if (histo)
	{
		while (var->p)
		{
			write(1, "\b", 1);
			write(1, " ", 1);
			write(1, "\b", 1);
			var->p--;
		}
		var->i = 0;
	}
	else if ((int)ft_strlen(*print) < var->line_old_len && var->p)
	{
		write(1, "\b", 1);
		write(1, " ", 1);
		write(1, "\b", 1);
		var->line_old_len = ft_strlen(*print);
		var->i = var->line_old_len;
		if (var->p > 0)
			var->p--;
		return (1);
	}
	return (0);
}

void	refresh_screen_supp_3(t_refresh *var, char *prefix, t_utils *utils)
{
	if (var->p == 0 && var->i == 0)
		while (*prefix)
		{
			ft_putchar_fd(*prefix, 1);
			prefix++;
			var->p++;
			if (var->p == utils->column_count)
			{
				ft_putchar_fd(10, 1);
				var->p = 0;
			}
		}
}

void	refresh_screen_supp_4(t_refresh *var, int *spec, t_utils *utils,
		char **print)
{
	if (var->p == utils->column_count && (var->p = 0) == 0)
		ft_putchar_fd(10, 1);
	if (print[0][var->i] == 9)
	{
		while (*spec < 4)
		{
			*spec = *spec + 1;
			ft_putchar_fd(' ', 1);
			var->p++;
			if (var->p == utils->column_count && (var->p = 0) == 0)
				ft_putchar_fd(10, 1);
		}
		*spec = 0;
		var->i++;
	}
	else
	{
		ft_putchar_fd(print[0][var->i++], 1);
		var->p++;
		if (var->p == utils->column_count && (var->p = 0) == 0)
			ft_putchar_fd(10, 1);
	}
}

void	refresh_screen(char **print, char *prefix,
		t_utils *utils, int histo)
{
	static t_refresh	var;
	int					spec;

	spec = 0;
	if (print == NULL && prefix == NULL && refresh_screen_supp_1(&var))
		return ;
	if (refresh_screen_supp_2(histo, &var, print))
		return ;
	refresh_screen_supp_3(&var, prefix, utils);
	while (print[0][var.i])
		refresh_screen_supp_4(&var, &spec, utils, print);
	var.line_old_len = ft_strlen(*print);
}
