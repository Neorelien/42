/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/04/12 12:03:46 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

t_sig g_sig;

void			ft_start_by_pipe(char ***env, t_utils *utils, char *line,
		t_parsing *parsing)
{
	int i;

	i = 0;
	if (isatty(0) == 1)
		return ;
	while (get_next_line(0, &line))
	{
		i = recursive_parsing(&line, parsing, i, utils);
		if (!ft_sep(*parsing))
			fonction_router(parsing, env, utils);
		parsing = new_list(parsing);
		i = 0;
		free(line);
		line = NULL;
		g_sig.pid = -1;
	}
	ft_exit(env, utils, 0);
}

void			main_supp_1(char ***env, t_utils *utils, t_parsing **parsing,
		char **line)
{
	if (**env == NULL)
	{
		ft_putstr_fd("ERROR, no env\n", 2);
		exit(1);
	}
	ft_signal();
	*parsing = new_list(NULL);
	init_utils(utils, *parsing, *env, line);
	utils->line_p = line;
	utils->tmp = malloc(sizeof(char*) * (ft_doubletab_len(*env) + 1));
	recopy_data(utils->tmp, *env, 0);
	*env = utils->tmp;
	ft_print_prefix(0, 0, env, utils);
	ft_start_by_pipe(env, utils, *line, *parsing);
}

void			main_supp_2(char ***env, t_main *main)
{
	ft_putstr_fd("termcaps init fail\n", 2);
	ft_exit(env, &main->utils, 1);
}

void			main_supp_3(t_main *main)
{
	if (main->line != NULL)
		free(main->line);
	main->line = NULL;
	tcsetattr(0, 0, &main->utils.s_termios_backup);
	ft_putstr_fd("exit\n", 1);
}

int				main(int argc, char **argv, char **env)
{
	t_main main;

	main_supp_4(&argc, &argv, &main);
	main_supp_1(&env, &main.utils, &main.parsing, &main.line);
	if (term_init(&main.utils))
	{
		while (shelline_gestion(&env, &main.utils, &main.line) > 0)
		{
			main.i = recursive_parsing(&main.line, main.parsing, main.i,
					&main.utils);
			if (!ft_sep(*main.parsing))
				ft_prefonction_router(main.parsing, &env, &main.utils);
			main.parsing = new_list(main.parsing);
			main.i = 0;
			free(main.line);
			main.line = NULL;
			g_sig.pid = -1;
		}
		main_supp_3(&main);
	}
	else
		main_supp_2(&env, &main);
	ft_exit(&env, &main.utils, 0);
	return (0);
}
