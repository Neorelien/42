/* *****************************************:w:********************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:55:18 by awery             #+#    #+#             */
/*   Updated: 2021/03/09 13:32:34 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

void	ft_other_exc(t_parsing *parsing, char **env, t_utils *utils)
{
	(void)env;
	(void)parsing;
	if (pipe(utils->pipefd) == -1)
		printf("error pipe");
	utils->cpid = fork();
	if (utils->cpid == 0) // lecture du fils
	{
		close(utils->pipefd[1]);
		parsing = new_list(NULL);
		read(utils->pipefd[0], &parsing->objet, 100);
		printf("objet = %s\n", parsing->objet);
		close(utils->pipefd[0]);
	}
	else // lecture du pere
	{
		close(utils->pipefd[0]);
		write(utils->pipefd[1], parsing->objet, ft_strlen(parsing->objet));
		close(utils->pipefd[1]);
		wait(NULL);
	}
}
