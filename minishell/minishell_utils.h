/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
/*   Updated: 2021/03/03 11:54:52 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS
# define MINISHELL_UTILS

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct	s_parsing
{
	char				*objet;
	char				*data;
	struct s_parsing	*next;
}				t_parsing;

#endif
