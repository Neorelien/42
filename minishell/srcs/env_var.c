/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:54:22 by awery             #+#    #+#             */
/*   Updated: 2021/03/20 00:04:50 by aurelien         ###   ########.fr       */
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

int		env_in_env(char **env, char *str)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (str[len] != '=' && str[i])
		len++;
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], str, len - 1) == 0 && env[i][len] == '=')
		{
			env[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}

void	add_env(int i, t_parsing *parsing, char ***env)
{
	int		len;
	char	**tmp;

	len = ft_doubletab_len(*env);
	tmp = *env;
	*env = malloc(sizeof(char*) * (len + 2));
	*env = recopy_data(*env, tmp);
	free(tmp);
	if (env_in_env(*env, parsing->data[i]))
		;
	else
	{
		env[0][len] = ft_strdup(parsing->data[i]);
		env[0][len + 1] = NULL;
	}
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

void	double_tab_sort(char **tabl)
{
	char	*temp;
	int		count;
	int		i;
	int		len;

	i = 0;
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

void	display_env_sort(char **env, int fd)
{
	int		i;

	double_tab_sort(env);
	i = 0;
	while (env[i] != NULL)
	{
		ft_putstr_fd(env[i], fd);
		write(fd, "\n", 1);
		i++;
	}
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
		{
		//	free(temp[i]);
			i++;
		}
		else
		{
			data[0][o] = temp[i];
			i++;
			o++;
		}
	}
	data[0][o] = NULL;
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

int		ft_unset(t_parsing *parsing, char ***env)
{
	int	i;

	i = 0;
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		if (in_db_tab(*env, parsing->data[i]))
			supp_env(env, parsing->data[i]);
		i++;
	}
	return (1);
}

int		ft_env(t_parsing *parsing, char **env, t_utils *utils)
{
	int		i;
	int		fd;

	i = 0;
	fd = write_with_separator(*parsing, env, utils, 1);
	while (env[i] != NULL)
	{
		ft_putstr_fd(env[i], fd);
		write(fd, "\n", 1);
		i++;
	}
	return (1);
}

int		ft_export(t_parsing *parsing, char ***env, t_utils *utils)
{
	int			i;
	int			fd;
	int			o;

	o = 0;
	i = 0;
	fd = write_with_separator(*parsing, *env, utils, 1);
	if (parsing->data != NULL && parsing->data[0] != NULL)
	{
		while (parsing->data[i] != NULL)
		{
			while (parsing->data[i][o] && parsing->data[i][o] != '=')
				if (!ft_isalnum(parsing->data[i][o++]))
					return (0);
			if (i == 0 && parsing->data[i][0] >= '0' &&
					parsing->data[i][0] <= '9')
				return (0);
			if (egal_in(parsing->data[i]) > -1)
				add_env(i, parsing, env);
			i++;
		}
	}
	else
	{
		display_env_sort(*env, fd);
		return (1);
	}
	return (1);
}
