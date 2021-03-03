/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/03 12:10:53 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

int main ()
{
	char		**line;
	t_parsing	*parsing;
	int			i;
	char		*temp;
	
	i = 0;
	line = malloc(sizeof(char*) * 1);
	temp = NULL;
	*line = NULL;
	while (get_next_line(1, line))
	{
		while ()
		free(*line);
		*line = NULL;
	}
	return (0);
}
