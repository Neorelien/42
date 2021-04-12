/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_supp_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurelien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 18:33:43 by aurelien          #+#    #+#             */
/*   Updated: 2021/04/12 12:05:24 by aurelien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int			selec_dest_sup_1(t_parsing *parsing)
{
	parsing->data = malloc(sizeof(char*) * 2);
	parsing->data[0] = ft_strdup("");
	parsing->data[1] = NULL;
	return (1);
}

char		**selec_dest(t_parsing *parsing, char **line,
		int *p, t_utils *utils)
{
	int		i;
	char	**tmp;

	i = 0;
	if ((line[0][*p] == '1' || line[0][*p] == '2' ||
				line[0][*p] == '0') && line[0][*p + 1] == '>')
	{
		utils->redir = line[0][*p] - 48;
		*p = *p + 1;
		return (NULL);
	}
	if (parsing->objet == NULL && (parsing->objet = ft_strdup("")))
		return (&parsing->objet);
	else if (parsing->data == NULL && selec_dest_sup_1(parsing))
		return (&parsing->data[0]);
	while (parsing->data[i] != NULL)
		i++;
	tmp = parsing->data;
	parsing->data = malloc(sizeof(char*) * (i + 2));
	recopy_data(parsing->data, tmp, 1);
	free(tmp);
	parsing->data[i] = ft_strdup("");
	parsing->data[i + 1] = NULL;
	return (&parsing->data[i]);
}

t_parsing	*ft_last_pars(t_parsing *parsing)
{
	if (parsing == NULL)
		return (NULL);
	while (parsing->next != NULL)
		parsing = parsing->next;
	return (parsing);
}

char		**recopy_data(char **data, char **temp, int freed)
{
	int	i;

	i = 0;
	while (temp[i] != NULL)
	{
		if (freed == 0)
			data[i] = ft_strdup(temp[i]);
		else
			data[i] = temp[i];
		i++;
	}
	data[i] = NULL;
	return (data);
}
