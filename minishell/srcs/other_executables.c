/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:43:03 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 20:45:52 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

char	**add_string_to_tab(char **tab_string, char *str)
{
	char	**tab_tmp;
	int		i;

	i = 0;
	if (tab_string == NULL)
	{
		tab_tmp = (char**)malloc(sizeof(char*) * 2);
		tab_tmp[i] = ft_strdup(str);
		tab_tmp[i + 1] = NULL;
		return (tab_tmp);
	}
	tab_tmp = (char**)malloc(sizeof(char*) *
			(ft_doubletab_len(tab_string) + 2));
	tab_tmp[i] = ft_strdup(str);
	while (tab_string[i] != NULL)
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

void	f_parent(t_parsing *parsing, char ***env, t_utils *utils, char **tmp)
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
		execve(&parsing->objet[2], parsing->data, *env);
	execve(parsing->objet, parsing->data, NULL);
	while (next_path(parsing, *env) &&
			execve(parsing->objet, parsing->data, NULL) == -1)
	{
		free(parsing->objet);
		parsing->objet = ft_strdup(*tmp);
	}
	printf("minishell : command not found: %s\n", *tmp);
	free(*tmp);
	free(*utils->line_p);
	ft_exit(env, utils, 1);
}

void	f_child(t_utils *utils, char **tmp)
{
	int	temp;

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
	free(*tmp);
}

void	ft_other_exc(t_parsing *parsing, char **env, t_utils *utils)
{
	char	*tmp;

	parsing->data = add_string_to_tab(parsing->data, parsing->objet);
	tmp = ft_strdup(parsing->objet);
	if (g_sig.pid != -2)
		g_sig.pid = fork();
	else
		g_sig.pid = 0;
	tcsetattr(0, 0, &utils->s_termios_backup);
	if (g_sig.pid == 0)
		f_parent(parsing, &env, utils, &tmp);
	else
		f_child(utils, &tmp);
}
