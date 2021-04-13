/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:40:20 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/13 14:00:00 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

int		get_objet_spp_1(int *i, t_parsing *parsing, char **line)
{
	if (is_separator_parsing(line[0], *i))
	{
		if (is_separator_parsing(line[0], *i) > 4)
		{
			parsing->separator[0] = '>';
			parsing->separator[1] = '>';
			parsing->separator[2] = 0;
			*i = *i + 2;
		}
		else
		{
			parsing->separator[0] = line[0][*i];
			*i = *i + 1;
		}
		return (1);
	}
	return (0);
}

void	get_objet_spp_2(t_get_objet *objet, char **line, int *i)
{
	if (line[0][*i] != objet->quote)
		ft_cpy(objet->res, line[0][*i]);
	else if (*i > 0 && line[0][*i - 1] == 92 && objet->quote == 34)
		ft_cpy(objet->res, line[0][*i]);
	else if ((objet->quote = 0) == 0)
		ft_cpy(objet->res, line[0][*i]);
}

int		gt3(char **line, int *i, t_get_objet *objet,
		t_parsing *parsing)
{
	if (is_separator_parsing(line[0], *i) > 4)
	{
		parsing->separator[0] = '>';
		parsing->separator[1] = '>';
		parsing->separator[2] = 0;
		*i = *i + 2;
	}
	else
	{
		parsing->separator[0] = line[0][*i];
		*i = *i + 1;
	}
	if (objet->res != NULL && *objet->res != NULL && objet->res[0][0] == 0)
	{
		free(*objet->res);
		*objet->res = NULL;
	}
	return (1);
}

void	get_objet_spp_4(char **line, t_get_objet *objet, int i)
{
	if (line[0][i] == 34 || line[0][i] == 39)
	{
		if (i > 0 && line[0][i - 1] != 92)
			objet->quote = line[0][i];
		if (i == 0)
			objet->quote = line[0][i];
		ft_cpy(objet->res, line[0][i]);
	}
	else
		ft_cpy(objet->res, line[0][i]);
}

int		get_objet(char **line, int i,
		t_parsing *parsing, t_utils *utils)
{
	t_get_objet	objet;

	if ((objet.quote = 0) == 0 && line[0][i])
		if (get_objet_spp_1(&i, parsing, line) ||
				!(objet.res = selec_dest(parsing, line, &i, utils)))
			return (i);
	while (((line[0][i] != ' ' || (line[0][i] == ' ' && objet.quote != 0) ||
					(line[0][i] == ' ' && line[0][i - 1] == 92)) && line[0][i]))
	{
		if (objet.quote != 0)
			get_objet_spp_2(&objet, line, &i);
		else if (is_separator_parsing(line[0], i) &&
				gt3(line, &i, &objet, parsing))
			break ;
		else
			get_objet_spp_4(line, &objet, i);
		i++;
	}
	if (objet.res != NULL && *objet.res != NULL && objet.res[0][0] == 0)
	{
		free(*objet.res);
		*objet.res = NULL;
	}
	return (i);
}
