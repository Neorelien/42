/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:54:22 by awery             #+#    #+#             */
/*   Updated: 2021/03/05 14:08:58 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		egal_in(char *str)
{
	int i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] == 0)
		return (-1);
	else
		return (i);
}

void	add_env(int i, t_parsing parsing, char **env)
{
	int		len;
	char	**tmp;

	len = ft_doubletab_len(env);
	tmp = env;
	env = malloc(sizeof(char*) * (len + 2));
	recopy_data(env, tmp);
	free(tmp);
	env[len] = ft_strdup(parsing.data[i]);
	env[len + 1] = NULL;
}

char	**mall_env(char **env)
{
	char	**res;
	int		len;

	len = ft_doubletab_len(env);
	res = malloc(sizeof(char*) * (len + 1));
	recopy_data(res, env);
	res[len] = NULL;
	return (res);
}

int		ft_export(t_parsing parsing, char **env)
{
	int		i;

	i = 0;
	write_with_separator(parsing);
	env = mall_env(env);	
	if (parsing.data != NULL)
	{
		while (parsing.data[i] != NULL)
		{
			if ((egal_in(parsing.data[i])) > -1)
				add_env(i, parsing, env);
			i++;
		}
	}
/*	else
	{
		display_env(env);
		return (1);
	}*/
	return (1);
}
