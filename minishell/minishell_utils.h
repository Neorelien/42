/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/05 13:46:34 by awery            ###   ########.fr       */
=======
/*   Updated: 2021/03/05 13:26:29 by cmoyal           ###   ########.fr       */
>>>>>>> 7214fc7c067d38942aa3a848e62c0e0a6ea4cd7b
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS
# define MINISHELL_UTILS

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "srcs/libft/libft.h"
#include "srcs/get_next_line/get_next_line.h"
#include <stdio.h>

typedef struct	s_parsing
{
	char				*objet;
	char				**data;
	char				separator[3];
	struct s_parsing	*next;
}				t_parsing;

# define OPEN_SQUOTE -2
# define OPEN_DQUOTE -3

void	recopy_data(char **data, char **temp);
int		ft_export(t_parsing parsing, char **env);
char	*ft_str_erase_set(char *str, char quote);
int		echo(t_parsing info);
size_t	ft_doubletab_len(char **doubletab);
int		is_separator(char *str);
int		write_with_separator(t_parsing info);
int		ft_display_rep(char **env);
int		ft_cd(t_parsing info, char **env);
int 	ft_pwd(t_parsing info);

#endif
