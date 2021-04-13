/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:36:12 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/13 14:04:47 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

char	*find_in_env(char **env, char *name)
{
	unsigned int	i;
	char			*path;
	char			*tmp;

	i = 0;
	while (!ft_isspace(name[i]) && name[i])
		i++;
	path = ft_substr(name, 0, i);
	tmp = ft_strjoin(path, "=");
	free(path);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(tmp, env[i], ft_strlen(tmp) - 1) == 0)
		{
			path = ft_strdup(env[i] + ft_strlen(tmp));
			free(tmp);
			return (path);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

size_t	ft_doubletab_len(char **doubletab)
{
	int	i;

	i = 0;
	if (doubletab == NULL)
		return (0);
	while (doubletab[i])
		i++;
	return (i);
}

void	ft_env_fd(t_parsing *info, char **env)
{
	char *tmp;

	if (info->next != NULL && info->next->objet[0] == '$')
	{
		tmp = info->next->objet;
		info->next->objet = find_in_env(env, info->next->objet + 1);
		free(tmp);
	}
}
