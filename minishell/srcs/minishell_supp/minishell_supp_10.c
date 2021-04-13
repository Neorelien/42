/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_10.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:45:28 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/13 13:59:38 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

void			put_histo_in_file(t_utils *utils)
{
	int	fd;

	if ((fd = open(utils->path, O_RDWR | O_CREAT, 0644 |
					O_DIRECTORY | O_NOFOLLOW)) == -1)
	{
		ft_error(strerror(errno), NULL);
		exit(1);
	}
	if (utils->com_history != NULL && utils->com_history_start->command != NULL)
		write_down_cfile(utils, fd);
	close(fd);
}

void			main_supp_4(int *argc, char ***argv, t_main *main)
{
	*argc = 0;
	*argv = NULL;
	main->i = 0;
}

int				ft_up_histo_supp_1(t_utils *utils)
{
	if (utils->com_history_end != NULL)
	{
		utils->position = utils->com_history_end;
		return (0);
	}
	else
		return (1);
}
