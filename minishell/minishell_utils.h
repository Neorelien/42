/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
/*   Updated: 2021/03/04 11:14:48 by cmoyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS
# define MINISHELL_UTILS

#include <stdlib.h>
#include <unistd.h>
#include "srcs/libft/libft.h"
#include "srcs/get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct	s_parsing
{
	char				*objet;
	char				**option;
	char				**data;
	char				separator[3];
	struct s_parsing	*next;
}				t_parsing;

# define OPEN_QUOTE -2

int	echo(t_parsing info);
size_t	ft_doubletab_len(char **doubletab);
int		is_separator(char *str);

#endif
