/* *****************************************:w:********************************* */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_executables.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:55:18 by awery             #+#    #+#             */
/*   Updated: 2021/03/09 13:03:27 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

void	ft_other_exc(t_parsing *parsing, char **env, t_utils *utils)
{
	(void)env;
	(void)parsing;
	if (pipe(utils->pipefd) == -1)
	;
	//fork();

}
