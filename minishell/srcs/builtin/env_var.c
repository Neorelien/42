/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:54:22 by awery             #+#    #+#             */
/*   Updated: 2021/04/13 13:57:41 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

void	double_tab_sort(char **tabl, int i, int len)
{
	char	*temp;
	int		count;

	count = 0;
	len = ft_doubletab_len(tabl);
	while (count <= len + 1)
	{
		if (ft_strncmp(tabl[i], tabl[i + 1], INT_MAX) <= 0)
		{
			if (i < len - 2)
				i++;
			else
				i = 0;
			count++;
		}
		else
		{
			temp = tabl[i];
			tabl[i] = tabl[i + 1];
			tabl[i + 1] = temp;
			count = 0;
		}
	}
}

void	display_env_sort(char ***env, int fd)
{
	int		i;

	double_tab_sort(*env, 0, 0);
	i = 0;
	while (env[0][i] != NULL)
	{
		ft_putstr_fd(env[0][i], fd);
		free(env[0][i]);
		write(fd, "\n", 1);
		i++;
	}
	free(env[0][i]);
	free(*env);
}

int		ft_export_supp_1(t_parsing *parsing, int i, int *o)
{
	while (parsing->data[i][*o] && parsing->data[i][*o] != '=')
	{
		if (!ft_isalnum(parsing->data[i][*o]) && parsing->data[i][*o] != '_')
		{
			ft_error("export: not valid in this context", parsing->data[i]);
			return (1);
		}
		*o = *o + 1;
	}
	return (0);
}

int		ft_export_supp_2(t_parsing *parsing, int i, char **error_ret)
{
	*error_ret = malloc(2);
	error_ret[0][0] = parsing->data[i][0];
	error_ret[0][1] = 0;
	ft_error("export: not an identifier", *error_ret);
	free(*error_ret);
	return (1);
}

int		ft_export(t_parsing *parsing, char ***env, t_utils *utils)
{
	int			i;
	int			o;
	char		*error_ret;

	if ((i = 0) == 0 && parsing->data != NULL && parsing->data[0] != NULL)
	{
		while ((o = 0) == 0 && parsing->data[i] != NULL)
		{
			if (ft_export_supp_1(parsing, i, &o))
				return (1);
			if ((i == 0 && parsing->data[i][0] >= '0' &&
				parsing->data[i][0] <= '9') || parsing->data[i][0] == '=')
				return (ft_export_supp_2(parsing, i, &error_ret));
			if (egal_in(parsing->data[i]) > -1 || !(i = i + 1))
				add_env(i++, parsing, env);
		}
	}
	else
	{
		utils->tmp = malloc(sizeof(char*) * (ft_doubletab_len(*env) + 1));
		recopy_data(utils->tmp, *env, 0);
		display_env_sort(&utils->tmp, 1);
		return (0);
	}
	return (0);
}
