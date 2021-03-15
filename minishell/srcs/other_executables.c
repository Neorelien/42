/* *****************************************:w:********************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:55:18 by awery             #+#    #+#             */
/*   Updated: 2021/03/15 13:17:07 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int			len_in_pipe(char sep, char *str)
{
	int	i;

	i = 0;
	while (str[i] != sep)
		i++;
	return (i);
}

void		cpy_from_pipe(char *from, char **to, char sep)
{
	int i;

	i = 0;
	while (from[i] != sep)
	{
		to[0][i] = from[i];
		i++;
	}
	to[0][i] = 0;
}

void		mall_data_fr_pipe(t_parsing *parsing, t_utils *utils, int *len, char *line)
{
	int	i;
	int	o;
	int	p;

	o = 1;
	i = *len;
	p = 0;
	parsing->data[0] = ft_strdup(parsing->objet);
	while (line[i] != -3 && line[i] != -4)
	{
	
		while (line[i++] != -2)
			p++;
		parsing->data[o++] = malloc(sizeof(char) * (p + 1));
		p = 0;
	}
}

void		copy_data_fr_pipe(t_parsing *parsing, t_utils *utils, int *len, char *line)
{
	int	o;
	int	p;

	o = 1;
	p = 0; 
	while (line[*len] != -3 && line[*len] != -4)
	{
		while (line[*len] != -2)
		{
			parsing->data[o][p++] = line[*len];
			*len = *len + 1;
		}
		parsing->data[o][p] = 0;
		*len = *len + 1;
		o++;
		p = 0;
	}
}

int			ft_data_count(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(line[i])
		if (line[i++] == -2)
			count++;
	return (count - 1);
}

void		ft_gmalloc_pars(t_parsing *parsing, t_utils *utils)
{
	int		tmp;
	int		len;
	char	*line;
	int		i;

	i = 0;
	get_next_line(utils->pipefd[0], &line);
	len = len_in_pipe(-1, line);
	parsing->objet = malloc(sizeof(char) * (len + 1));
	cpy_from_pipe(line, &parsing->objet, -1);
	len = len + 1;
	if (line[len] == -2)
	{
		parsing->data = malloc(sizeof(char*) * (ft_data_count(line) + 2));
		parsing->data[ft_data_count(line) + 1] = NULL;
		len = len + 1;
		mall_data_fr_pipe(parsing, utils, &len, line);
		copy_data_fr_pipe(parsing, utils, &len, line);
	}
	if (line[len] == -3)
	{
		if (line[len + 1] != -4)
			parsing->separator[0] = line[len + 1];
		if (line[len + 2] != -4)
			parsing->separator[1] = line[len + 2];
		if (line[len + 3] != -4)
			parsing->separator[2] = line[len + 3];
	}
}

t_parsing	*get_pipe(t_utils *utils)
{
	t_parsing	*parsing;
	int			i;

	i = 0;
	parsing = new_list(NULL);
	utils->parsing_start = parsing;
	ft_gmalloc_pars(parsing, utils);
	return (parsing);
}

void		send_in_pipe(int fd, t_parsing *parsing)
{
	char	c;
	int		i;

	i = 0;
	if (parsing->objet != NULL)
	{
		write(fd, parsing->objet, ft_strlen(parsing->objet));
		c = -1;
		write(fd, &c, 1);
	}
	while (parsing->data != NULL && parsing->data[i] != NULL)
	{
		if (c == -1 && (c = -2) == -2)
			write(fd, &c, 1);

		write(fd, parsing->data[i], ft_strlen(parsing->data[i]));
		i++;
		c = -2;
		write(fd, &c, 1);
	}
	if (parsing->separator[0] != 0 && (c = -3) == -3)
	{
		write(fd, &c, 1);
		write(fd, parsing->separator, ft_strlen(parsing->separator));
	}
	c = -4;
	write(fd, &c, 1);
}

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

void		ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
//	free(str);
}

int			next_path(t_parsing *parsing, char **env)
{
	char		**path;
	int			i;
	static int	p;
	char		*tmp;


	i = ft_find_env(env);
	if (i > -1)
		path = ft_split(env[i], ':');
	while (path[p])
	{
		tmp = path[p];
		path[p] = ft_strjoin(path[p], "/");
		free(tmp);
		if (p == 0)
		{
			tmp = path[p];
			path[p] = path[p] + 5;
			free(tmp);
		}
		tmp = parsing->objet;
		parsing->objet = ft_strjoin(path[p], parsing->objet);
		free(tmp);
	//	ft_free(path);
		p++;
		return (1);
	}
	return (0);
}

void		ft_other_exc(t_parsing *parsing, char **env, t_utils *utils)
{
	char	*tmp;
	(void)env;
	(void)parsing;
	if (pipe(utils->pipefd) == -1)
		printf("error pipe");
	utils->cpid = fork();
	if (utils->cpid == 0) // lecture du fils
	{
		close(utils->pipefd[1]);
		parsing = get_pipe(utils);
		if (parsing->data == NULL)
		{
			parsing->data = malloc(sizeof(char*));
			*parsing->data = malloc(1);
			parsing->data[0][0] = 0;
		}
		tmp = ft_strdup(parsing->objet);
		close(utils->pipefd[0]);
		while (next_path(parsing, env) && execve(parsing->objet, parsing->data, env) == -1)
			parsing->objet = ft_strdup(tmp);
	//	clean_parsing(parsing);
	}
	else // lecture du pere
	{
		close(utils->pipefd[0]);
		send_in_pipe(utils->pipefd[1], parsing);
		close(utils->pipefd[1]);
		wait(NULL);
	}
}
