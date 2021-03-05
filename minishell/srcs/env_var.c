/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:54:22 by awery             #+#    #+#             */
/*   Updated: 2021/03/05 13:16:40 by awery            ###   ########.fr       */
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

int	ft_export(t_parsing parsing, char **env)
{
	char	*new_var;
	char	*data;
	int		i;
	int		o;

	i = 0;
	o = 0;
	write_with_separator(parsing);	
	if (parsing.data != NULL)
		if ((i = egal_in(parsing.data)) < 0)
			return (0);
//	else
//	{
//		ft_env(parsing, env);
//		return (1);
//	}
	
}
