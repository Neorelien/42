/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:54:22 by awery             #+#    #+#             */
/*   Updated: 2021/03/05 12:16:37 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_utils.h"

int		egal_in(char *str)
{
	int i;

	i = 0;
	while (str[i] != '=' && str[i])
		i++;
	if (str[i] = 0)
		return (-1);
	else
		return (i);
}

void	ft_export(t_paring parsing, char **env)
{
	char	*new_var;
	char	*data;
	int		i;
	
	if (parsing.data != NULL)
		if (egal_in(parsing.data) < 0)

//	else
//		ft_env(env);
	
}
