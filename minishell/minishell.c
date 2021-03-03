/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/03 16:16:53 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int		get_nude_obj(int i, char *line, t_parsing *parsing)
{
	char	*res;
	char	*tmp;
	char	to_join[2];

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	while (line[i] != ' ' && line[i])
	{
		tmp = res;
		to_join[0] = line[i];
		res = ft_strjoin_gnl(res, to_join);
		free(tmp);
		i++;
	}
	parsing->objet = res;
	i++;//le prochain caractere qui sera lu est celui juste apres le quote
	return (i);
}
int		get_obj_dquote(int i, char *line, t_parsing *parsing)
{
	char	*res;
	char	*tmp;
	char	to_join[2];

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	while (line[i] != 34)
	{
		if (!line[i])
			return (OPEN_QUOTE);
		tmp = res;
		to_join[0] = line[i];
		res = ft_strjoin_gnl(res, to_join);
		free(tmp);
		i++;
	}
	parsing->objet = res;
	i++;//le prochain caractere qui sera lu est celui juste apres le quote
	return (i);
}

int		get_obj_squote(int i, char *line, t_parsing *parsing)
{
	char	*res;
	char	*tmp;
	char	to_join[2];

	res = malloc(sizeof(char) * 1);
	res[0] = 0;
	to_join[1] = 0;
	while (line[i] != 39)
	{
		if (!line[i])
			return (OPEN_QUOTE);
		tmp = res;
		to_join[0] = line[i];
		res = ft_strjoin_gnl(res, to_join);
		free(tmp);
		i++;
	}
	parsing->objet = res;
	i++;//le prochain caractere qui sera lu est celui juste apres le quote
	return (i);
}

int		get_objet(char *line, int i, t_parsing *parsing)
{
	int		quote[2];

	if ((quote[0] = 0) == 0 && line[i] == 39)
		quote[0] = 1;
	if ((quote[1] = 0) == 0 && line[i] == 34)
		quote[1] = 1;
	if (quote[0] == 1 || quote[1] == 1)
		i++;
	if (quote[0])
		return (get_obj_squote(i, line, parsing));
	else if (quote[1])
		return (get_obj_dquote(i, line, parsing));
	else
		return (get_nude_obj(i, line, parsing));
	return (0);
}

int		main(void)
{
	char		**line;
	t_parsing	*parsing;
	t_parsing	*start;
	int			i;
	
	parsing = malloc(sizeof(t_parsing) * 1);
	start = parsing;
	i = 0;
	line = malloc(sizeof(char*) * 1);
	*line = NULL;
	while (get_next_line(1, line))
	{
	//	while (line[0][i])
	//	{
			while (line[0][i] == ' ')
				i++;
			i = get_objet(*line, i, parsing);
			printf("objet = %s\n", parsing->objet);
	//	}
		i = 0;
		free(*line);
		*line = NULL;
	}
	return (0);
}
