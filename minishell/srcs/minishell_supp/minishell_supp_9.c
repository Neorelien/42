/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_9.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:41:35 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/13 14:10:12 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

void		get_command_file(t_utils *utils)
{
	int		fd;
	char	*line;

	if ((fd = open(utils->path, O_RDWR | O_CREAT, 0644 |
					O_DIRECTORY | O_NOFOLLOW)) == -1)
	{
		ft_error(strerror(errno), NULL);
		exit(1);
	}
	utils->history_len = 0;
	utils->position = NULL;
	utils->com_history = NULL;
	utils->com_history_end = NULL;
	utils->com_history_start = NULL;
	while (get_next_line(fd, &line))
	{
		new_hlist(line, utils);
		free(line);
	}
	free(line);
	close(fd);
}

void		get_p_file_path_supp(t_utils *utils, char *path, int *i, int *p)
{
	utils->path = ft_strdup(path);
	if (ft_strncmp(path, "//.", 2) == 0)
	{
		free(utils->path);
		utils->path = ft_strdup(&path[3]);
		while (utils->path[*i])
		{
			if (ft_strncmp(&utils->path[*i], "minishell", 8) == 0)
				*p = *i;
			*i = *i + 1;
		}
	}
	else
		while (utils->path[*i] != '.' && (*i = *i + 1))
			*p = *i;
}

void		get_p_file_path(t_utils *utils)
{
	int		i;
	char	*path;
	char	*tmp;
	int		p;

	p = -1;
	i = 0;
	path = getenv("_");
	if (path == NULL)
		exit(1);
	if (ft_strncmp(path, "/usr/bin/valgrind", 16) == 0)
		utils->path = ft_strdup(".p_command.hst");
	else
	{
		get_p_file_path_supp(utils, path, &i, &p);
		if (p == -1 &&
		printf("problem with the directory name, has to be \"minishell\" \n"))
			exit(1);
		utils->path[p] = 0;
		tmp = utils->path;
		utils->path = ft_strjoin_gnl(utils->path, ".p_command.hst");
		free(tmp);
	}
}

void		init_utils(t_utils *utils, t_parsing *parsing, char **env,
		char **line)
{
	g_sig.pid = -1;
	*line = NULL;
	utils->pwd = find_in_env(env, "PWD");
	utils->oldpwd = find_in_env(env, "OLDPWD");
	utils->parsing_start = parsing;
	get_p_file_path(utils);
	get_command_file(utils);
	g_sig.pid = -1;
	utils->fdin[0] = 0;
	utils->fdin[1] = 1;
	utils->fdout[0] = 0;
	utils->fdout[1] = 1;
	utils->savefd = -1;
	utils->savefdout = -1;
	utils->return_value = 0;
	utils->redir = 1;
	utils->line_eof = NULL;
}

void		write_down_cfile(t_utils *utils, int fd)
{
	t_historical *histo;

	histo = utils->com_history_start;
	if (histo->command != NULL)
	{
		ft_putstr_fd(histo->command, fd);
		ft_putchar_fd(10, fd);
		while (histo->next != NULL)
		{
			histo = histo->next;
			if (histo->command != NULL && histo->command[0] != 0)
			{
				ft_putstr_fd(histo->command, fd);
				ft_putchar_fd(10, fd);
			}
		}
	}
}
