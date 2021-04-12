/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_7.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:30:59 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 14:09:17 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int		free_ret(void *to_free)
{
	free(to_free);
	return (1);
}

int		ft_signal(void)
{
	signal(SIGINT, handler_next);
	signal(SIGQUIT, handler_quit);
	return (1);
}

void	recup_line_supp_1(char **line)
{
	free(*line);
	*line = ft_strdup("");
}

void	recup_line_supp_2(char **line, t_utils *utils, char *prefix)
{
	*line = ft_up_histo(utils, line);
	utils->line_EOF = *line;
	refresh_screen(line, prefix, utils, 1);
}

void	recup_line_supp_3(char **line, t_utils *utils, char *prefix)
{
	*line = ft_down_histo(utils, line);
	utils->line_EOF = *line;
	refresh_screen(line, prefix, utils, 1);
}
