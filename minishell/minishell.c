/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/03 11:49:52 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int main (int argc, char **argv)
{
	char		**line;
	t_parsing	*parsing;
	int			i;
	char		**splited;
	
	i = 0;
	line = malloc(sizeof(char*) * 1);
	*line = NULL;
	splited = NULL;
	while (splited != NULL ||  get_next_line(1, line))
	{
		splited = ft_split(*line, ' ');
		
		free(*line);
		*line = NULL;
	}
	return (0);
}
