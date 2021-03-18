/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/18 11:37:02 by aurelien         ###   ########.fr       */
=======
/*   Updated: 2021/03/18 13:13:17 by cmoyal           ###   ########.fr       */
>>>>>>> d70df55fbfb465158d73361f443874d5c48111b0
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
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct	s_parsing
{
	char				*objet;
	char				**data;
	char				separator[3];
	struct s_parsing	*next;
}				t_parsing;

typedef struct	s_utils
{
	char		*pwd;
	char		**tmp;
	pid_t		cpid;
	int			pipefd[2];
	t_parsing	*parsing_start;
	char		result;
	char		**data;
}				t_utils;

typedef struct	s_sig
{
	pid_t	pid;
}				t_sig;

extern t_sig g_sig;

# define OPEN_SQUOTE -2
# define OPEN_DQUOTE -3
# define TEST printf("ON VA LA\n")

void		test_struct(t_parsing *parsing);
void		data_formation(t_parsing *parsing, char ***env);
void		ft_cpy(char **res, char c);
int			ft_lstsize(t_parsing *lst);
t_parsing	*ft_lstlast(t_parsing *lst);
int			is_separator_parsing(char *str, int i);
int			clean_parsing(t_parsing *parsing);
t_parsing	*new_list(t_parsing *previous_lst);
void		ft_other_exc(t_parsing *parsing, char **env, t_utils *utils);
int			ft_unset(t_parsing *parsing, char ***env);
int			ft_env(t_parsing *parsing, char **env, t_utils *utils);
int			ft_error(char *str, char *strbis);
char		**recopy_data(char **data, char **temp);
int			ft_export(t_parsing *parsing, char ***env, t_utils *utils);
char		*ft_str_erase_set(char *str, char quote);
int			ft_echo(t_parsing info, char ***env, t_utils *utils);
size_t		ft_doubletab_len(char **doubletab);
int			is_separator(char *str);
int			write_with_separator(t_parsing info, char **env, t_utils *utils, int fd);
int			ft_display_rep(char **env, t_utils utils);
int			ft_cd(t_parsing info, char ***env, t_utils *utils);
int			ft_pwd(t_parsing info, char ***env, t_utils *utils);
int			env_in_env(char **env, char *str);
char		*find_in_env(char **env, char *name);
void		fonction_router(t_parsing *parsing, char ***env, t_utils *utils);
void		check_to_next(t_parsing info, char ***env, t_utils *utils);
int			ft_sep(t_parsing info);
int			ft_next_is_pipe(t_parsing info, char **env, t_utils *utils, int flag);
void		handler_next(int sign);
void		handler_quit(int sign);
#endif
