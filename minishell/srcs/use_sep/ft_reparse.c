/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reparse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoyal <cmoyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:27:30 by cmoyal            #+#    #+#             */
/*   Updated: 2021/04/13 14:02:18 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell_utils.h"

int		ft_reparse_count(t_parsing *info, int add)
{
	int			i;
	t_parsing	*parse;

	parse = info;
	while (parse->next != NULL && is_separator(parse->separator) > 2)
	{
		i = 0;
		parse = parse->next;
		while (parse->data != NULL && parse->data[i])
		{
			add++;
			i++;
		}
	}
	return (add + 1);
}

void	ft_reparse_malloc(t_parsing *info, int add)
{
	char	**doubletab;
	int		i;

	i = 0;
	add = ft_reparse_count(info, add);
	doubletab = (char**)malloc(sizeof(char*) * add);
	while (info->data != NULL && info->data[i])
	{
		doubletab[i] = info->data[i];
		i++;
	}
	free(info->data);
	info->data = doubletab;
}

void	ft_reparse(t_parsing *info)
{
	int			sep;
	int			i;
	int			add;
	t_parsing	*parse;

	add = 0;
	while (info->data && info->data[add] != NULL)
		add++;
	if ((sep = is_separator(info->separator)) == 3 || sep == 4 || sep == 5)
	{
		ft_reparse_malloc(info, add);
		parse = info;
		while (parse->next != NULL && is_separator(parse->separator) > 2)
		{
			i = -1;
			parse = parse->next;
			while (parse->data != NULL && parse->data[++i])
				if (info->objet == NULL)
					info->objet = ft_strdup(parse->data[i]);
				else
					info->data[add++] = ft_strdup(parse->data[i]);
		}
		info->data[add] = NULL;
	}
}
