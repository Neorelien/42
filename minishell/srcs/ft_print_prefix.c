/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prefix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:53:17 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/12 16:32:49 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int	ft_save_prefix(char ***env, t_utils *utils, t_prefix *prefix)
{
	prefix->env_stat = env;
	prefix->utils_stat = utils;
	return (0);
}

int	ft_print_prefix(int check_prefix, int activate, char ***env, t_utils *utils)
{
	static t_prefix	prefix;
	char			*str;
	char			*tmp;

	if (check_prefix && prefix.alrd_activate && (prefix.alrd_activate = 0) == 0)
		return (1);
	else if (check_prefix && !prefix.alrd_activate)
		return (0);
	if (activate)
	{
		ft_putstr_fd("\n", 1);
		str = ft_display_rep(*prefix.env_stat, *prefix.utils_stat);
		tmp = str;
		str = ft_strjoin(str, "-> ");
		free(tmp);
		tmp = ft_strdup("");
		refresh_screen(NULL, NULL, NULL, 0);
		refresh_screen(&tmp, str, prefix.utils_stat, 0);
		free(tmp);
		free(str);
		prefix.alrd_activate = 1;
	}
	else
		ft_save_prefix(env, utils, &prefix);
	return (0);
}
