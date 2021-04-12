/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:39:21 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 15:28:00 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

char			*ft_up_histo(t_utils *utils, char **line)
{
	char	*line_ret;
	char	*tmp;

	if (utils->position == NULL)
	{
		if (ft_up_histo_supp_1(utils))
			return (*line);
	}
	else if (line[0][0] != 0)
	{
		if (utils->position->previous != NULL)
			utils->position = utils->position->previous;
		else
			return (*line);
	}
	line_ret = ft_strdup(utils->position->command);
	if (ft_strncmp(*line, line_ret, ft_strlen(*line) - 1) == 0 &&
			ft_strlen(*line) == ft_strlen(line_ret) && (tmp = ft_strdup(*line)))
	{
		free(line_ret);
		line_ret = ft_up_histo(utils, &tmp);
	}
	free(*line);
	return (line_ret);
}

char			*ft_down_histo(t_utils *utils, char **line)
{
	char	*line_ret;
	char	*tmp;

	if (utils->position == NULL)
		return (*line);
	else
	{
		if (utils->position->next != NULL)
			utils->position = utils->position->next;
		else
		{
			free(*line);
			return (ft_strdup(""));
		}
	}
	line_ret = ft_strdup(utils->position->command);
	if (ft_strncmp(*line, line_ret, ft_strlen(*line) - 1) == 0 &&
			ft_strlen(*line) == ft_strlen(line_ret))
	{
		tmp = ft_strdup(*line);
		free(line_ret);
		line_ret = ft_down_histo(utils, &tmp);
	}
	free(*line);
	return (line_ret);
}

int				shelline_gestion(char ***env, t_utils *utils, char **line)
{
	int		ret;
	char	*prefix;
	char	*tmp;

	prefix = ft_strdup("");
	free(prefix);
	prefix = ft_display_rep(*env, *utils);
	tmp = prefix;
	prefix = ft_strjoin(prefix, "-> ");
	free(tmp);
	*line = ft_strdup("");
	refresh_screen(line, prefix, utils, 0);
	while ((ret = ft_recup_line(line, utils, prefix)) > 0)
		;
	free(prefix);
	if (ret == 0)
		return (1);
	if (ret == -1)
		return (0);
	return (-1);
}

t_historical	*add_next_command(t_historical *previous, char *line)
{
	t_historical *new;

	new = malloc(sizeof(t_historical));
	new->command = ft_strdup(line);
	new->next = NULL;
	new->previous = previous;
	return (new);
}

void			new_hlist(char *line, t_utils *utils)
{
	if (utils->history_len == 0)
	{
		if (*line != 0)
		{
			utils->com_history = add_next_command(NULL, line);
			utils->com_history_start = utils->com_history;
			utils->com_history_end = utils->com_history;
			utils->history_len++;
		}
	}
	else
	{
		if (*line != 0)
		{
			utils->com_history->next =
				add_next_command(utils->com_history, line);
			utils->com_history = utils->com_history->next;
			utils->com_history_end = utils->com_history;
			utils->history_len++;
		}
	}
}
