/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executables_supp_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:39:48 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 20:59:57 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int			ft_find_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL && ft_strncmp(env[i], "PATH=", 4) != 0)
		i++;
	if (env[i] == NULL)
		return (-1);
	return (i);
}

void		ft_free(char ***str)
{
	int	i;

	i = 0;
	while (str[0][i] != NULL)
		free(str[0][i++]);
}

void		next_path_supp(t_parsing *parsing, char **path, int *p)
{
	char	*tmp;

	tmp = path[*p];
	path[*p] = ft_strjoin(path[*p], "/");
	free(tmp);
	if (*p == 0)
	{
		tmp = path[*p];
		path[*p] = ft_strdup(path[*p] + 5);
		free(tmp);
	}
	tmp = parsing->objet;
	parsing->objet = ft_strjoin(path[*p], parsing->objet);
	free(tmp);
	ft_free(&path);
	free(path);
	*p = *p + 1;
}

int			next_path(t_parsing *parsing, char **env)
{
	char		**path;
	int			i;
	static int	p;

	i = ft_find_env(env);
	if (i > -1)
		path = ft_split(env[i], ':');
	else
		return (0);
	if (path[p])
	{
		next_path_supp(parsing, path, &p);
		return (1);
	}
	ft_free(&path);
	free(path);
	return (0);
}

char		*ft_get_shell_name(void)
{
	char	*res;
	int		i;
	int		o;

	i = 0;
	res = getenv("SHELL");
	if (res == NULL)
		exit(1);
	while (res[i])
	{
		if (res[i] == '/')
			o = i;
		i++;
	}
	return (&res[o + 1]);
}
