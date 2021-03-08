/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:54:22 by awery             #+#    #+#             */
/*   Updated: 2021/03/08 10:40:15 by awery            ###   ########.fr       */
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

void	add_env(int i, t_parsing *parsing, char ***env)
{
	int		len;
	char	**tmp;

	len = ft_doubletab_len(*env);
	tmp = *env;
	*env = malloc(sizeof(char*) * (len + 2));
	recopy_data(*env, tmp);
	free(tmp);
	env[0][len] = ft_strdup(parsing->data[i]);
	env[0][len + 1] = NULL;
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

void	double_tab_sort(char **tab)
{
	char	*temp;
	int		count;
	int		i;
	int		len;

	i = 0;
	count = 0;
	len = ft_doubletab_len(tab);
	while (count <= len + 1)
	{
		if (ft_strncmp(tab[i], tab[i + 1], INT_MAX) <= 0)
		{
			if (i < len - 2)
				i++;
			else
				i = 0;
			count++;
		}
		else
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			count = 0;
		}
	}
}

void	display_env_sort(char ***env, int fd)
{
	int		i;

	double_tab_sort(*env);
	i = 0;
	while (env[0][i] != NULL)
	{
		ft_putstr_fd(env[0][i], fd);
		write(fd, "\n", 1);
		i++;
	}
}

void	recopy_less_data(char **data, char **temp, char *str)
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
			i++;
		else
		{
			data[o] = temp[i];
			i++;
			o++;
		}
	}
	data[o] = NULL;
}

void	supp_env(char ***env, char *str)
{
	int		len;
	char	**tmp;

	len = ft_doubletab_len(*env);
	tmp = *env;
	*env = malloc(sizeof(char*) * (len));
	recopy_less_data(*env, tmp, str);
	free(tmp);
}

int		in_db_tab(char **tab, char *str)
{
	int i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (tab[i] != NULL)
	{
		if (ft_strncmp(tab[i], str, len - 1) == 0 && tab[i][len] == '=')
			return (1);
		i++;
	}
	return (0);
}

int		ft_unset(t_parsing *parsing, char ***env)
{
	int	i;
	char ** tmp;

	i = 0;

	if (env_alrdy_mall == 0 && (env_alrdy_mall = 1))
	{
		tmp = *env;
		*env = mall_env(*env);
	}
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		if (in_db_tab(*env, parsing->data[i]))
			supp_env(env, parsing->data[i]);
		i++;
	}
	return (1);
}

int		ft_env(t_parsing *parsing, char ***env)
{
	int		i;
	int		fd;

	i = 0;
	fd = write_with_separator(*parsing);
	while (env[0][i] != NULL)
	{
		ft_putstr_fd(env[0][i], fd);
		write(fd, "\n", 1);
		i++;
	}
	return (1);
}

int		ft_export(t_parsing *parsing, char ***env)
{
	int			i;
	int			fd;
	char		**tmp;

	i = 0;
	fd = write_with_separator(*parsing);
	if (env_alrdy_mall == 0 && (env_alrdy_mall = 1))
	{
		tmp = *env;
		*env = mall_env(*env);
	}
	if (parsing->data != NULL && parsing->data[0] != NULL)
	{
		while (parsing->data[i] != NULL)
		{
			if ((egal_in(parsing->data[i])) > -1)
				add_env(i, parsing, env);
			i++;
		}
	}
	else
	{
		display_env_sort(env, fd);
		return (1);
	}
	return (1);
}
