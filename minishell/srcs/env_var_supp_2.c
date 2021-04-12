/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_supp_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 19:46:28 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 20:01:55 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		in_db_tab(char **tabl, char *str)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (tabl[i] != NULL)
	{
		if (ft_strncmp(tabl[i], str, len - 1) == 0 && tabl[i][len] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	supp_env(char ***env, char *str)
{
	int		len;
	char	**tmp;

	len = ft_doubletab_len(*env);
	tmp = *env;
	*env = malloc(sizeof(char*) * (len));
	recopy_less_data(env, tmp, str);
	free(tmp);
}

int		ft_unset(t_parsing *parsing, char ***env)
{
	int	i;

	i = 0;
	if (parsing->data == NULL || parsing->data[0] == NULL)
	{
		printf("unset: not enough arguments\n");
		return (1);
	}
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		if (in_db_tab(*env, parsing->data[i]))
			supp_env(env, parsing->data[i]);
		i++;
	}
	return (0);
}

int		ft_env(t_parsing *parsing, char **env)
{
	int		i;

	i = 0;
	while (parsing->data != NULL && parsing->data[i] != NULL)
		if (ft_strncmp("env", parsing->data[i++], 2) != 0)
		{
			printf("env: %s: No such file or directory\n", parsing->data[--i]);
			return (127);
		}
	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr_fd(env[i], 1);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}

int		double_tab_sort_supp_1(int *count)
{
	*count = *count + 1;
	return (1);
}
