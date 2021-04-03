/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
/*   Updated: 2021/04/03 13:21:02 by cmoyal           ###   ########.fr       */
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
#include <term.h>
#include <ncurses.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <signal.h>

typedef struct	s_parsing
{
	char	    		*objet;
	char	    		**data;
	char	    		separator[3];
	struct	s_parsing	*next;
}	    	t_parsing;

typedef struct	s_historical
{
	struct	s_historical		*previous;
	char				*command;
	struct	s_historical		*next;
}		t_historical;

typedef struct	s_utils
{
	char			*pwd;
	char			*oldpwd;
	char			**tmp;
	int			pipefork[2];
	int			fdout[2];
	int			fdin[2];
	t_parsing		*parsing_start;
	char			result;
	char			**data;
	struct			termios s_termios;
	struct			termios s_termios_backup;
	char				*tgetent_var;
	t_historical		*com_history;
	t_historical		*com_history_start;
	t_historical		*com_history_end;
	t_historical		*position;
	int			history_len;
	int		savefd;
	int		savefdout;
	int		return_value;
	char				**line_p;
}		t_utils;

typedef struct	s_sig
{
	pid_t			pid;
	int				prefix;
	char			***env;
	t_utils			*utils;
	char			***line;
}		t_sig;

extern t_sig g_sig;

# define OPEN_SQUOTE -2
# define OPEN_DQUOTE -3
# define TEST printf("ON VA LA\n")


void		ft_print_prefix(int	activate, char ***env, t_utils *utils);
int				shelline_gestion(char ***env, t_utils *utils, char **line);
void			put_histo_in_file(t_utils *utils);
void			ft_exit(char ***env, t_utils *utils, int ret);
void			new_hlist(char *line, t_utils *utils);
t_historical	*add_next_command(t_historical *previous, char *line);
int				term_init(t_utils *utils);
int				ft_signal();
void		test_struct(t_parsing *parsing);
void		data_formation(t_parsing *parsing, char ***env, t_utils *utils);
void		ft_cpy(char **res, char c);
int			ft_lstsize(t_parsing *lst);
t_parsing	*ft_lstlast(t_parsing *lst);
int			is_separator_parsing(char *str, int i);
t_parsing	*new_list(t_parsing *previous_lst);
void		ft_other_exc(t_parsing *parsing, char **env, t_utils *utils);
int			ft_unset(t_parsing *parsing, char ***env);
int			ft_env(t_parsing *parsing, char **env, t_utils *utils);
int			ft_error(char *str, char *strbis);
char		**recopy_data(char **data, char **temp, int freed);
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
void    ft_redir(t_parsing info, char **env, t_utils *utils);
void            ft_pipe_settings(t_utils *utils);
void ft_reroll(t_parsing info, char **env, t_utils *utils);
int reset_fd_one(t_utils *utils);
int reset_fd_zero(t_utils *utils);
#endif
