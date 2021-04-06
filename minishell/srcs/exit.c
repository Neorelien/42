/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 13:41:11 by awery             #+#    #+#             */
/*   Updated: 2021/04/06 19:31:35 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

void		ft_clean_parsing(t_parsing *parsing)
{
	int	i;

	i = 0;
	if (parsing->objet != NULL)
		free(parsing->objet);
	while (parsing->data != NULL && parsing->data[i] != NULL)
		free(parsing->data[i++]);
	if (parsing->data != NULL)
		free(parsing->data);
	if (parsing->next != NULL)
		ft_clean_parsing(parsing->next);
	free(parsing);
}

void		ft_clean_historical(t_historical *histo)
{
	if (histo->command != NULL)
		free(histo->command);
	if (histo->next != NULL)
		ft_clean_historical(histo->next);
	free(histo);
}

void		ft_clean_utils(t_utils *utils)
{
	if (utils->pwd != NULL)
		free(utils->pwd);
	if (utils->oldpwd != NULL)
		free(utils->oldpwd);
	if (utils->line_EOF != NULL)
		free(utils->line_EOF);
}

void	ft_clean_env(char ***env)
{
	int	i;

	i = 0;
	while (env[0] != NULL && env[0][i] != NULL)
		free(env[0][i++]);
	if (env[0] != NULL)
		free(env[0]);
}

void		ft_exit(char ***env, t_utils *utils, int ret)
{
	if (utils!= NULL)
		put_histo_in_file(utils);
	if (utils != NULL)
		ft_clean_parsing(utils->parsing_start);
	if (utils != NULL)
		ft_clean_historical(utils->com_history_start);
	if (utils != NULL)
		ft_clean_utils(utils);
	if (env != NULL)
		ft_clean_env(env);
	//	system("leaks minishell");
	exit(ret);
}
