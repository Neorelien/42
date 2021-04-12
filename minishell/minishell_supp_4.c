/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 19:05:27 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 16:43:09 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void		ft_restart_on_pipe(t_parsing *parsing, char ***env, t_utils *utils)
{
	int			try;
	t_parsing	*info;
	char		*line;

	line = NULL;
	try = 0;
	info = NULL;
	while (parsing->separator[0] != '|')
	{
		if (try == 0)
			try = 1;
		parsing = parsing->next;
	}
	parsing = parsing->next;
	if (try == 1)
	{
		ft_start_by_pipe(env, utils, line, parsing);
		return ;
	}
	fonction_router(parsing, env, utils);
}

void		fd_management(t_utils *utils, char ***env, t_parsing *parsing)
{
	if (utils->fdout[1] != 1)
	{
		if (utils->savefd != -1)
		{
			close(1);
			dup2(utils->savefd, 1);
			utils->savefd = -1;
		}
		utils->fdout[1] = 1;
	}
	if (utils->fdin[1] != 1)
	{
		close(utils->fdin[1]);
		utils->fdin[1] = 1;
	}
	if (utils->fdin[0] != 0)
	{
		close(utils->fdin[0]);
		utils->fdin[0] = 0;
	}
	reset_fd_one(utils);
	reset_fd_zero(utils);
	check_to_next(*parsing, env, utils);
}

void		find_the_true_way(t_parsing *parsing, char ***env, t_utils *utils)
{
	if (ft_strncmp(parsing->objet, "echo", 4) == 0)
		utils->return_value = ft_echo(*parsing, env, utils);
	else if (ft_strncmp(parsing->objet, "cd", 2) == 0)
		utils->return_value = ft_cd(*parsing, env, utils);
	else if (ft_strncmp(parsing->objet, "pwd", 3) == 0)
		utils->return_value = ft_pwd(*parsing, env, utils);
	else if (ft_strncmp(parsing->objet, "export", 6) == 0)
		utils->return_value = ft_export(parsing, env, utils);
	else if (ft_strncmp(parsing->objet, "env", 3) == 0)
		utils->return_value = ft_env(parsing, *env);
	else if (ft_strncmp(parsing->objet, "unset", 5) == 0)
		utils->return_value = ft_unset(parsing, env);
	else if (ft_strncmp(parsing->objet, "exit", 5) == 0)
	{
		if (parsing->data != NULL && parsing->data[0] != NULL)
			ft_exit(env, utils, check_return(parsing->data[0]));
		else
			ft_exit(env, utils, 0);
	}
	else if (parsing->objet != NULL)
		ft_other_exc(parsing, *env, utils);
}

void		fonction_router(t_parsing *parsing, char ***env, t_utils *utils)
{
	ft_redir(*parsing, *env, utils);
	find_the_true_way(parsing, env, utils);
	fd_management(utils, env, parsing);
	if (ft_next_is_pipe(*parsing, *env, utils, 0))
		ft_restart_on_pipe(parsing, env, utils);
	if (g_sig.pid == -2)
		exit(1);
}

int			term_init(t_utils *utils)
{
	int		ret;
	char	*term_type;

	ret = 0;
	term_type = getenv("TERM");
	if (term_type == NULL)
		exit(1);
	if ((ret = tgetent(NULL, term_type)))
	{
		if (tcgetattr(0, &utils->s_termios) == -1)
			return (-1);
		if (tcgetattr(0, &utils->s_termios_backup) == -1)
			return (-1);
		utils->s_termios.c_lflag &= ~(ICANON);
		utils->s_termios.c_lflag &= ~(ECHO);
		if (tcsetattr(0, 0, &utils->s_termios) == -1)
			return (-1);
		utils->column_count = tgetnum("co");
	}
	return (ret);
}
