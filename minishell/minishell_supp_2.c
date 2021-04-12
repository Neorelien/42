/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:35:53 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 12:06:29 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

void		ft_cpy(char **res, char c)
{
	char	to_join[2];
	char	*tmp;

	to_join[0] = c;
	to_join[1] = 0;
	tmp = *res;
	*res = ft_strjoin_gnl(*res, to_join);
	free(tmp);
}

t_parsing	*new_list(t_parsing *previous_lst)
{
	t_parsing	*parsing;

	previous_lst = ft_last_pars(previous_lst);
	parsing = malloc(sizeof(t_parsing));
	parsing->separator[0] = 0;
	parsing->separator[1] = 0;
	parsing->separator[2] = 0;
	parsing->next = NULL;
	parsing->objet = NULL;
	parsing->data = NULL;
	if (previous_lst != NULL)
		previous_lst->next = parsing;
	return (parsing);
}

int			recursive_parsing(char **line, t_parsing *parsing, int i,
		t_utils *utils)
{
	while (line[0][i] == ' ')
		i++;
	if (!line[0][i])
		return (i);
	i = get_objet(line, i, parsing, utils);
	if (parsing->separator[0] != 0)
		i = recursive_parsing(line, new_list(parsing), i, utils);
	else if (i >= 0 && line[0][i])
		i = recursive_parsing(line, parsing, i, utils);
	return (i);
}

int			check_return(char *str)
{
	int i;

	i = 0;
	while (str[i])
		if (!ft_isalnum(str[i++]))
		{
			printf("minishell: exit: lol : argument numérique nécessaire\n");
			return (2);
		}
	return (ft_atoi(str));
}

void		ft_prefonction_router(t_parsing *parsing, char ***env,
		t_utils *utils)
{
	data_formation(parsing, env, utils);
	ft_reparse(parsing);
	fonction_router(parsing, env, utils);
}
