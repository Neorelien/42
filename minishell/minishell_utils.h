/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/03 14:57:28 by awery            ###   ########.fr       */
=======
/*   Updated: 2021/03/03 14:26:15 by cmoyal           ###   ########.fr       */
>>>>>>> 8a343064b95802a04f7a18a6aadc66eba014fe4a
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

#endif
