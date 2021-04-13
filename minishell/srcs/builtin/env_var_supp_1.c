/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_supp_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:43:35 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/13 13:57:53 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

int		env_in_env(char **env, char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '=')
		len++;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, len) == 0 && env[i][len] == '=')
		{
			free(env[i]);
			env[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

void	recopy_less_data(char ***data, char **temp, char *str)
{
	int	i;
	int	o;
	int len;

	len = ft_strlen(str);
	i = 0;
	o = 0;
	while (temp[i] != NULL)
	{
		if (ft_strncmp(temp[i], str, len - 1) == 0 && temp[i][len] == '=')
			free(temp[i++]);
		else
		{
			data[0][o] = temp[i];
			i++;
			o++;
		}
	}
	data[0][o] = NULL;
}

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

char	**mall_env(char **env)
{
	char	**res;
	int		len;

	len = ft_doubletab_len(env);
	res = malloc(sizeof(char*) * (len + 1));
	recopy_data(res, env, 1);
	res[len] = NULL;
	return (res);
}

void	add_env(int i, t_parsing *parsing, char ***env)
{
	int		len;
	char	**tmp;

	len = ft_doubletab_len(*env);
	tmp = *env;
	*env = malloc(sizeof(char*) * (len + 2));
	*env = recopy_data(*env, tmp, 1);
	free(tmp);
	if (env_in_env(*env, parsing->data[i]))
		;
	else
	{
		env[0][len] = ft_strdup(parsing->data[i]);
		env[0][len + 1] = NULL;
	}
}
