/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_6.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:29:18 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/13 14:08:56 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

int			recup_line_supp_4(char **line, t_utils *utils)
{
	utils->line_eof = NULL;
	if (**line != 0)
		new_hlist(*line, utils);
	refresh_screen(NULL, NULL, NULL, 0);
	write(0, "\n", 1);
	utils->position = NULL;
	return (0);
}

void		recup_line_supp_5(char **line, t_utils *utils,
		char *prefix, char *buf)
{
	utils->line_eof = NULL;
	ft_cpy(line, buf[0]);
	refresh_screen(line, prefix, utils, 0);
}

void		recup_line_supp_6(char **line, t_utils *utils,
		char *prefix)
{
	if (ft_strlen(*line) > 0)
		line[0][ft_strlen(*line) - 1] = 0;
	refresh_screen(line, prefix, utils, 0);
}

int			recup_line_ultimate(char **line, t_utils *utils, char *prefix,
		char *buf)
{
	if (ft_print_prefix(1, 0, NULL, NULL))
		recup_line_supp_1(line);
	if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
		recup_line_supp_2(line, utils, prefix);
	else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
		recup_line_supp_3(line, utils, prefix);
	else if (buf[0] == 10)
		return (recup_line_supp_4(line, utils));
	else if (ft_isprint(buf[0]))
		recup_line_supp_5(line, utils, prefix, buf);
	else if (buf[0] == 127)
		recup_line_supp_6(line, utils, prefix);
	else if (buf[0] == 4)
	{
		utils->line_eof = NULL;
		if (**line == 0)
			return (-1);
	}
	return (-2);
}

int			ft_recup_line(char **line, t_utils *utils, char *prefix)
{
	char	buf[4];
	int		ret;
	int		ret_ulti;

	buf[3] = 0;
	buf[2] = 0;
	buf[1] = 0;
	buf[0] = 0;
	ret = read(0, &buf, 3);
	if (ret != -1 && buf[0] != 0)
	{
		ret_ulti = recup_line_ultimate(line, utils, prefix, buf);
		if (ret_ulti != -2)
			return (ret_ulti);
		utils->line_eof = NULL;
		if (ret == 0)
			return (-1);
		return (1);
	}
	return (-2);
}
