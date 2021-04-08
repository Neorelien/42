/* *****************************************:w:********************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:55:18 by awery             #+#    #+#             */
/*   Updated: 2021/04/08 15:12:00 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int			len_in_pipe(char sep, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
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

void		mall_data_fr_pipe(t_parsing *parsing, int *len, char *line)
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

void		copy_data_fr_pipe(t_parsing *parsing, int *len, char *line)
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
	int		len;
	char	*line;
	int		i;
	char	*buff;

	i = 0;
	buff = malloc(sizeof(char) * 2);
	buff[1] = 0;
	line = ft_strdup("");
	while (read(utils->pipefork[0], buff, 1))
	{
		*utils->tmp = line;
		line = ft_strjoin(line, buff);
		free(*utils->tmp);
	}
	len = len_in_pipe(-1, line);
	parsing->objet = malloc(sizeof(char) * (len + 1));
	cpy_from_pipe(line, &parsing->objet, -1);
	len = len + 1;
	if (line[len] == -2)
	{
		parsing->data = malloc(sizeof(char*) * (ft_data_count(line) + 2));
		parsing->data[ft_data_count(line) + 1] = NULL;
		len = len + 1;
		mall_data_fr_pipe(parsing, &len, line);
		copy_data_fr_pipe(parsing, &len, line);
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
	ft_gmalloc_pars(parsing, utils);
	return (parsing);
}

void		send_in_pipe(int fd, t_parsing *parsing)
{
	char	c;
	int		i;

	i = 0;
	c = 0;
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

void		ft_free(char ***str)
{
	int	i;

	i = 0;
	while (str[0][i] != NULL)
		free(str[0][i++]);
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
	else
		return (0);
	if	(path[p])
	{
		tmp = path[p];
		path[p] = ft_strjoin(path[p], "/");
		free(tmp);
		if (p == 0)
		{
			tmp = path[p];
			path[p] = ft_strdup(path[p] + 5);
			free(tmp);
		}
		tmp = parsing->objet;
		parsing->objet = ft_strjoin(path[p], parsing->objet);
		free(tmp);
		ft_free(&path);// INVALID POINTER ASKIP
		free(path);
		p++;
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
	while (res[i])
	{
		if (res[i] == '/')
			o = i;
		i++;
	}
	return (&res[o + 1]);
}

char	**add_string_to_tab(char **tab_string, char *str)
{
	char **tab_tmp;
	int i;

	i = 0;
	if (tab_string == NULL)
	{
		tab_tmp = (char**)malloc(sizeof(char*) * 2);
		tab_tmp[i] = ft_strdup(str);
		tab_tmp[i + 1] = NULL;
		return (tab_tmp);
	}
	tab_tmp = (char**)malloc(sizeof(char*) * (ft_doubletab_len(tab_string) + 2));
	tab_tmp[i] = ft_strdup(str);
	while(tab_string[i] != NULL)
	{
		tab_tmp[i + 1] = tab_string[i];
		i++;
	}
	tab_tmp[i + 1] = NULL;
	free(tab_string);
	tab_string = tab_tmp;
	return (tab_string);
}

void	ft_clean_fork(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (parsing->objet != NULL)
		free(parsing->objet);
	while (parsing->data != NULL && parsing->data[i] != NULL)
		free(parsing->data[i++]);
	if (i > 0)
		free(parsing->data);
}

void	ft_other_exc(t_parsing *parsing, char **env, t_utils *utils)
{
	char	*tmp;
	int		temp;
	char	*shell;

	parsing->data = add_string_to_tab(parsing->data, parsing->objet);
	tmp = ft_strdup(parsing->objet);
	if (g_sig.pid != -2)
		g_sig.pid = fork();
	else
		g_sig.pid = 0;
	tcsetattr(0, 0, &utils->s_termios_backup);
	if (g_sig.pid == 0) // lecture de l'enfant
	{
		if (utils->fdin[1] != 1 && utils->fdin[0] != 0)
		{	
			close(utils->fdin[1]);
			dup2(utils->fdin[0], 0);
			close(utils->fdin[0]);
		}
		if (utils->fdout[1] != 1 && utils->fdout[0] != 0)
			close(utils->fdout[0]);
		if (parsing->objet[0] == '.' && parsing->objet[1] == '/')
			execve(&parsing->objet[2], parsing->data, env);
		execve(parsing->objet, parsing->data, NULL);
		while (next_path(parsing, env) && execve(parsing->objet, parsing->data, NULL) == -1)
		{
			free(parsing->objet);
			parsing->objet = ft_strdup(tmp);
		}
		shell = ft_get_shell_name();
		printf("%s: command not found: %s\n", shell, tmp);
		free(tmp);
		free(*utils->line_p);
		ft_exit(&env, utils, 1);
	}
	else // lecture du parent
	{
		if (utils->fdin[1] != 1 && utils->fdin[0] != 0)
		{
			close(utils->fdin[0]);
			close(utils->fdin[1]);
			utils->fdin[1] = 1;
			utils->fdin[0] = 0;
		}
		if (utils->fdout[1] != 1)                                                   
		{                                                                           
			close(1);                                                               
			dup2(utils->savefd, 1);                                                 
			utils->savefd = -1;                                                     
			utils->fdout[1] = 1;                                                    
		}
		temp = g_sig.pid;
		wait(&utils->return_value);
		if (WIFEXITED(utils->return_value))
			utils->return_value = WEXITSTATUS(utils->return_value);
		else
			utils->return_value = 128 + WTERMSIG(utils->return_value);
		g_sig.pid = -1;
		term_init(utils);
		free(tmp);
	}
}
