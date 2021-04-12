/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:29:02 by awery             #+#    #+#             */
/*   Updated: 2021/04/12 20:00:47 by aurelien         ###   ########.fr       */
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

typedef struct	s_redir
{
	int			sep;
	char		*result;
	int			fd;
}				t_redir;

typedef struct	s_cd
{
	char	*path;
	char	*oldpath;
}				t_cd;

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

typedef	struct	s_get_objet
{
	char		**res;
	int			quote;
}				t_get_objet;

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
	int					history_len;
	int					savefd;
	int					savefdout;
	int					return_value;
	char				**line_p;
	char				*line_EOF;
	int					column_count;
	int					redir;
	char				*path;
	int					i;
	int					quote;
	char				*new_obj;
}		t_utils;

typedef	struct	s_main
{
	char		*line;
	t_parsing	*parsing;
	int			i;
	t_utils		utils;
}				t_main;

typedef	struct	s_refresh
{
	int	i;
	int	p;
	int	line_old_len;
}		t_refresh;

typedef struct	s_sig
{
	pid_t			pid;
}		t_sig;

typedef	struct	s_look
{
	char	*env_name;
	char	*env_cont;
	int		o;
	char	*tmp;
	char	*ret;
}				t_look;

extern t_sig g_sig;

int		double_tab_sort_supp_1(int *count);
void	add_env(int i, t_parsing *parsing, char ***env);
int		egal_in(char *str);
void	recopy_less_data(char ***data, char **temp, char *str);
int		look_for_bs_token(char **objet, int i, char **new_obj);
int		look_for_bs(char **objet, int quote, int i, char **new_obj);
void	trans_env(char **objet, char ***env, t_utils *utils);
int		is_token_remplace(char c, char **objet);
int		look_for_env(char **objet, char ***env, t_utils *utils);
int		quote_status(char **objet, int *quote, int i);
int				ft_up_histo_supp_1(t_utils *utils);
void			main_supp_4(int *argc, char ***argv, t_main *main);
void		write_down_cfile(t_utils *utils, int fd);
void		init_utils(t_utils *utils, t_parsing *parsing, char **env,
		char **line);
char	    *ft_down_histo(t_utils *utils, char **line);
char	    *ft_up_histo(t_utils *utils, char **line);
void	    recup_line_supp_1(char **line);
void	    recup_line_supp_2(char **line, t_utils *utils, char *prefix);
void	    recup_line_supp_3(char **line, t_utils *utils, char *prefix);
int	    ft_recup_line(char **line, t_utils *utils, char *prefix);
int		get_objet(char **line, int i,
		t_parsing *parsing, t_utils *utils);
int	check_return(char *str);
int		recursive_parsing(char **line, t_parsing *parsing, int i,
		t_utils *utils);
t_parsing   *ft_last_pars(t_parsing *parsing);
char	**selec_dest(t_parsing *parsing, char **line, int *p, t_utils *utils);
void	refresh_screen(char **print, char *prefix, t_utils *utils, int histo);
int		ft_print_prefix(int check, int	activate, char ***env, t_utils *utils);
int				shelline_gestion(char ***env, t_utils *utils, char **line);
void			put_histo_in_file(t_utils *utils);
void			ft_exit(char ***env, t_utils *utils, int ret);
void			new_hlist(char *line, t_utils *utils);
t_historical	*add_next_command(t_historical *previous, char *line);
int				term_init(t_utils *utils);
int				ft_signal();
void		test_struct(t_parsing *parsing);
void		data_formation(t_parsing *parsing, char ***env, t_utils *utils);
int			ft_cpy(char **res, char c);
int			ft_lstsize(t_parsing *lst);
t_parsing	*ft_lstlast(t_parsing *lst);
int			is_separator_parsing(char *str, int i);
t_parsing	*new_list(t_parsing *previous_lst);
void		ft_other_exc(t_parsing *parsing, char **env, t_utils *utils);
int			ft_unset(t_parsing *parsing, char ***env);
int			ft_env(t_parsing *parsing, char **env);
int			ft_error(char *str, char *strbis);
char		**recopy_data(char **data, char **temp, int freed);
int			ft_export(t_parsing *parsing, char ***env, t_utils *utils);
char		*ft_str_erase_set(char *str, char quote);
int			ft_echo(t_parsing info, char ***env, t_utils *utils);
int			is_separator(char *str);
int			write_with_separator(t_parsing info, char **env, t_utils *utils, int fd);
char		*ft_display_rep(char **env, t_utils utils);
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
void ft_reparse(t_parsing *info);
void	ft_prefonction_router(t_parsing *parsing, char ***env, t_utils *utils);
void	ft_start_by_pipe(char ***env, t_utils *utils, char *line, t_parsing *parsing);
void	ft_reparse(t_parsing *info);
void    add_env_pwd(char *str, char ***env);
char *ft_strjoin_slash(char *str, char *str_bis);
char *ft_home_dir(char **env);
size_t	ft_doubletab_len(char **tabl);
#endif
