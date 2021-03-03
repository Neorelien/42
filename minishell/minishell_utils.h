/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/03 16:16:55 by awery            ###   ########.fr       */
=======
/*   Updated: 2021/03/03 15:54:51 by cmoyal           ###   ########.fr       */
>>>>>>> 74669c730328c95556b1d653214c2a40bb8fc980
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
	char				**option;
	char				**data;
	struct s_parsing	*next;
}				t_parsing;

# define OPEN_QUOTE -2

int	echo(t_parsing info);
size_t	ft_doubletab_len(char **doubletab);

#endif
