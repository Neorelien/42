/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/31 11:55:54 by awery            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_utils.h"

t_sig g_sig;


char	*ft_str_erase_set(char *str, char quote)
{
  char	*res;
  int		o;
  int		i;

  i = 0;
  o = 0;
  //	printf("srtr = %s\n", str);
  while (str[i])
  {
    if (str[i] == quote)
      i++;
    else
    {
      i++;
      o++;
    }
  }
  //printf("o = %d\n", o);
  res = malloc(sizeof(char) * (o + 1));
  i = 0;
  o = 0;
  while (str[i])
  {
    if (str[i] == quote)
      i++;
    else
      res[o++] = str[i++];
  }
  //	printf("srtr = %s\n", str);
  res[o] = 0;
  return (res);
}

int		no_escape(char **line, int i)
{
  if (line[0][i] != 92)
    return (0);
  if (line[0][i + 1] == '$')
    return (1);
  if (line[0][i + 1] == '"')
    return (1);	
  if (line[0][i + 1] == 92)
    return (1);
  if (line[0][i + 1] == 0)
    return (1);
  return (0);
}

char	**selec_dest(t_parsing *parsing, char quote)
{
  int		i;
  char	**tmp;

  i = 0;
  if (parsing->objet == NULL)
  {
    parsing->objet = ft_strdup("");
    return (&parsing->objet);
  }
  else if (parsing->objet != NULL && parsing->data == NULL && quote > 0)
    return (&parsing->objet);
  else if (parsing->data == NULL)
  {
    parsing->data = malloc(sizeof(char*) * 2);
    parsing->data[0] = ft_strdup("");
    parsing->data[1] = NULL;
    return (&parsing->data[0]);
  }
  else if (parsing->data != NULL && quote > 0)
  {
    while (parsing->data[i])
      i++;
    return (&parsing->data[i - 1]);
  }
  while (parsing->data[i] != NULL)
    i++;
  tmp = parsing->data;
  parsing->data = malloc(sizeof(char*) * (i + 2));
  recopy_data(parsing->data, tmp, 1);
  free(tmp);
  parsing->data[i] = ft_strdup("");
  parsing->data[i + 1] = NULL;
  return (&parsing->data[i]);
}

void	ft_cpy(char **res, char c)
{
  char	to_join[2];
  char	*tmp;

  to_join[0] = c;
  to_join[1] = 0;
  tmp = *res;
  *res = ft_strjoin_gnl(*res, to_join);
  free(tmp);
}

int		get_objet(char **line, int i, t_parsing *parsing)
{
  char		**res;
  static char	quote;
 
  if (line[0][i])
  {
    if (is_separator_parsing(line[0], i))
    {
      if (is_separator_parsing(line[0], i) > 4)
      {
	parsing->separator[0] = '>';
	parsing->separator[1] = '>';
	parsing->separator[2] = 0;
	i = i + 2;
      }
      else
	parsing->separator[0] = line[0][i++];
      return (i);
    }
    res = selec_dest(parsing, quote);
  }
  while ((line[0][i] != ' ' || (line[0][i] == ' ' && quote != 0) ) &&
      line[0][i])
  {
    if (quote != 0)
    {
      if (line[0][i] != quote)
	ft_cpy(res, line[0][i]);
      else if (i > 0 && line[0][i - 1] == 92 && quote == 34) 
	ft_cpy(res, line[0][i]);
      else if ((quote = 0) == 0)
	ft_cpy(res, line[0][i]);
    }
    else if (is_separator_parsing(line[0], i))
    {
      if (is_separator_parsing(line[0], i) > 4)
      {
	parsing->separator[0] = '>';
	parsing->separator[1] = '>';
	parsing->separator[2] = 0;
	i = i + 2;
      }
      else
	parsing->separator[0] = line[0][i++];
      if (*res != NULL && res[0][0] == 0)
      {
	free(*res);
	*res = NULL;
      }
      break ;
    }
    else
    {
      if (line[0][i] == 34 || line[0][i] == 39)
      {
	if (i > 0 && line[0][i - 1] != 92)
	  quote = line[0][i];
	if (i == 0)
	  quote = line[0][i];
	ft_cpy(res, line[0][i]);
      }
      else
	ft_cpy(res, line[0][i]);
    }
    i++;
  }
  if (*res != NULL && res[0][0] == 0)
  {
    free(*res);
    *res = NULL;
  }
  if (quote == 39)
    return (OPEN_SQUOTE);
  if (quote == 34)
    return (OPEN_DQUOTE);
  return (i);
}

t_parsing   *ft_last_pars(t_parsing *parsing)
{
  if (parsing == NULL)
    return (NULL);
  while (parsing->next != NULL)
    parsing = parsing->next;
  return (parsing);
}

t_parsing   *new_list(t_parsing *previous_lst)
{
  t_parsing	*parsing;
  
  previous_lst = ft_last_pars(previous_lst);
  parsing = malloc(sizeof(t_parsing));
  parsing->separator[0] = 0;
  parsing->separator[1] = 0;
  parsing->separator[2] = 0;
  parsing->next = NULL;
  parsing->objet = NULL;
  parsing->data = NULL;
  if (previous_lst != NULL)
    previous_lst->next = parsing;
  return (parsing);
}

char	**recopy_data(char **data, char **temp, int freed)
{
  int	i;

  i = 0;
  while (temp[i] != NULL)
  {
	if (freed == 0)
		data[i] = ft_strdup(temp[i]);
	else
		data[i] = temp[i];
    i++;
  }
  data[i] = NULL;
  return (data);
}

int		recursive_parsing(char **line, t_parsing *parsing, int i)
{
  while (line[0][i] == ' ')
    i++;
  if (!line[0][i])
    return (i);
  i = get_objet(line, i, parsing);
  if (parsing->separator[0] != 0)
    i = recursive_parsing(line, new_list(parsing), i);
  else if (i >= 0 && line[0][i])
    i = recursive_parsing(line, parsing, i);
  return (i);
}

void	test_struct(t_parsing *parsing)
{
  int i;

  i= 0;
  if (parsing->objet != NULL)
    printf("objet =%s|\n", parsing->objet);
  while (parsing->data != NULL && parsing->data[i] != NULL)
  {
    printf("data %d =%s|\n", i, parsing->data[i]);
    i++;
  }
  if (parsing->separator[0] != 0)
    printf("sep = %s\n", parsing->separator);
  if (parsing->next != NULL)
    test_struct(parsing->next);
}

void	fonction_router(t_parsing *parsing, char ***env, t_utils *utils)
{
  data_formation(parsing, env, utils);
  ft_redir(*parsing, *env, utils);
  if (ft_strncmp(parsing->objet, "echo", 4) == 0)
    utils->return_value = ft_echo(*parsing, env, utils);	
  else if (ft_strncmp(parsing->objet, "cd", 2) == 0)
    utils->return_value = ft_cd(*parsing, env, utils);
  else if (ft_strncmp(parsing->objet, "pwd", 3) == 0)
    utils->return_value = ft_pwd(*parsing, env, utils);
  else if (ft_strncmp(parsing->objet, "export", 6) == 0)
    utils->return_value = ft_export(parsing, env, utils);
  else if (ft_strncmp(parsing->objet, "env", 3) == 0)
    utils->return_value = ft_env(parsing, *env, utils);
  else if (ft_strncmp(parsing->objet, "unset", 5) == 0)
    utils->return_value = ft_unset(parsing, env);
  else if (ft_strncmp(parsing->objet, "exit", 5) == 0)
    ft_exit(env, utils, 0);
  else if (parsing->objet != NULL)
    ft_other_exc(parsing, *env, utils);
  if (utils->fdout[1] != 1)
  {
    if (utils->savefd != -1)
    {
      close(1);
      dup2(utils->savefd, 1);
      utils->savefd = -1;
    }
    utils->fdout[1] = 1;
  }
  if (utils->fdin[1] != 1)                         
  {                                              
    close(utils->fdin[1]);                                              
    utils->fdin[1] = 1;                                                 
  }
  if (utils->fdin[0] != 0)                         
  {                                              
    close(utils->fdin[0]);                                              
    utils->fdin[0] = 0;                                                 
  }
  reset_fd_one(utils);
  reset_fd_zero(utils);
  check_to_next(*parsing, env, utils);
  if (ft_next_is_pipe(*parsing, *env, utils, 0))
    fonction_router(parsing->next, env, utils);
  if (g_sig.pid == -2)
    exit(1);
}

int	ft_signal()
{
  signal(SIGINT, handler_next);
  signal(SIGQUIT, handler_quit);
  return (1);
}

void	refresh_screen(char **print, int *print_char)
{
  int	    i;

  i = 0;
  if (*print_char > 0)
  {
    while (i++ < *print_char)
      ft_putchar_fd('\b', 0);
    while (i-- > 0)
      ft_putchar_fd(' ', 0);
    while (i++ < *print_char)
      ft_putchar_fd('\b', 0);
  }
  ft_putstr_fd(*print, 0);
  *print_char = ft_strlen(*print);
}

int	free_ret(void *to_free)
{
  free(to_free);
  return (1);
}

char	    *ft_up_histo(t_utils *utils, char **line)
{
  char	*line_ret;
  char	*tmp;

  if (utils->position == NULL)
  {
    if (utils->com_history_end != NULL)
      utils->position = utils->com_history_end;
    else
      return (*line);
  }
  else
  {
    if (utils->position->previous != NULL)
      utils->position = utils->position->previous;
    else
      return (*line);
  }
  line_ret = ft_strdup(utils->position->command);
  if (ft_strncmp(*line, line_ret, ft_strlen(*line) - 1) == 0)
  {
    tmp =  ft_strdup(*line);
    line_ret = ft_up_histo(utils, &tmp);
  }
  free(*line);
  return (line_ret);
}

char	    *ft_down_histo(t_utils *utils, char **line)
{
  char	*line_ret;
  char	*tmp;

  if (utils->position == NULL)
    return (*line);
  else
  {
    if (utils->position->next != NULL)
      utils->position = utils->position->next;
    else
    {
      free(*line);
      return (ft_strdup(""));
    }
  }
  line_ret = ft_strdup(utils->position->command);
  if (ft_strncmp(*line, line_ret, ft_strlen(*line) - 1) == 0)
  {
    tmp =  ft_strdup(*line);
    line_ret = ft_down_histo(utils, &tmp);
  }
  free(*line);
  return (line_ret);
}

int	    ft_recup_line(char **line, t_utils *utils)
{
  char		buf[4];
  int		ret;
  int		i;
  static int	print_char;

  i = 0;
  buf[3] = 0;
  buf[2] = 0;
  buf[1] = 0;
  buf[0] = 0;
  ret = read(0, &buf, 3);
  if (ret != -1 && buf[0] != 0)
  {
    if (g_sig.prefix == -1)
    {
      free(*line);
      *line = ft_strdup("");
      print_char = 0;
      g_sig.prefix = 1;
    }
    if (buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
    {
      *line = ft_up_histo(utils, line);
      refresh_screen(line, &print_char);
    }
    else if (buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
    {
      *line = ft_down_histo(utils, line);
      refresh_screen(line, &print_char);
    }
    else if (buf[0] == 10)
    {
      if (**line != 0)
	new_hlist(*line, utils);
      refresh_screen(line, &print_char);
      write(0, "\n", 1);
      print_char = 0;
      utils->position = NULL;
      return (0);
    }
    else if (ft_isprint(buf[0]))
    {
      ft_cpy(line, buf[0]);    
      refresh_screen(line, &print_char);
    }
    else if (buf[0] == 127)
    {
      if (ft_strlen(*line) > 0)
	line[0][ft_strlen(*line) - 1] = 0;
      refresh_screen(line, &print_char);
    }
    else if (buf[0] == 4)
    {
      if (**line == 0)
	return (-1);
    }
    if (ret == 0)
      return (-1);
    return (1);
  }
  return (-2);
}

int		shelline_gestion(char ***env, t_utils *utils, char **line)
{
  int	ret;

  if (g_sig.prefix == 0 || g_sig.prefix == -1)
  {
    ft_display_rep(*env, *utils);
    write(0, "-> ", 3);
    *line = ft_strdup("");
    g_sig.prefix = 1;
  }
  while ((ret = ft_recup_line(line, utils)) > 0)
      ;
  g_sig.prefix = 0;
  if (ret == 0)
    return (1);
  if (ret == -1)
    return (0);
  return (-1);
}

int	term_init(t_utils *utils)
{
  int ret = 0;

  char *term_type = getenv("TERM");

  if ((ret = tgetent(NULL, term_type)))// Fonction que vous aurez créé avec un tgetent dedans. 
  {
    if (tcgetattr(0, &utils->s_termios) == -1)
      return (-1);

    if (tcgetattr(0, &utils->s_termios_backup) == -1)
      return (-1);

    utils->s_termios.c_lflag &= ~(ICANON); /* Met le terminal en mode non canonique. La fonction read recevra les entrées clavier en direct sans attendre qu'on appuie sur Enter */
    utils->s_termios.c_lflag &= ~(ECHO); /* Les touches tapées au clavier ne s'affficheront plus dans le terminal */

    if (tcsetattr(0, 0, &utils->s_termios) == -1)
      return (-1);
  }
  //  if (term_type != NULL)
  //  free(term_type);
  return (ret);
}

void	get_quote(char **line, int quote, t_utils *utils)
{
  int	ret;

  free(*line);
  *line = ft_strdup("");
  if (quote == OPEN_DQUOTE)
    write(1, "dquote> ", 8);
  else
    write(1, "quote> ", 8);
  while ((ret = ft_recup_line(line, utils)))
    ;
  if (ret == -1)
    ft_error("unexpected EOF while looking for matching", "\'\"\'");
}

void	get_open_quote(int *i, char **line, t_parsing *parsing, t_utils *utils)
{
  char *tmp;

  get_quote(line, *i, utils);
  tmp = *line;
  *line = ft_strjoin("\n", *line);
  *i = 0;
  free(tmp);
  *i = recursive_parsing(line, ft_lstlast(parsing), *i);
}

t_historical	*add_next_command(t_historical *previous, char *line)
{
  t_historical *new;

  new = malloc(sizeof(t_historical));
  new->command = ft_strdup(line);
  new->next = NULL;
  new->previous = previous;
  return (new);
}

void		test_up_cfile(t_historical *list)
{
  printf("line =%s|\n", list->command);
  while (list->previous != NULL)
  {
    list = list->previous;
    if (list->command != NULL)
      printf("line =%s|\n", list->command);
    else
      printf("command = NULL\n");
  }
}

void		test_down_cfile(t_historical *list)
{
  printf("line =%s|\n", list->command);
  while (list->next != NULL)
  {
    list = list->next;
    if (list->command != NULL)
      printf("line =%s|\n", list->command);
    else
      printf("command = NULL\n");
  }
}

void		new_hlist(char *line, t_utils *utils)
{
  if (utils->history_len == 0)
  {
    if (*line != 0)
    {
      utils->com_history = add_next_command(NULL, line);
      utils->com_history_start = utils->com_history;
      utils->com_history_end = utils->com_history;
      utils->history_len++;
    }
  }
  else
  {
    if (*line != 0)
    {
      utils->com_history->next = add_next_command(utils->com_history, line);
      utils->com_history = utils->com_history->next;
      utils->com_history_end = utils->com_history;
      utils->history_len++;
    }
  }
}

void		get_command_file(t_utils *utils)

{
  int	fd;
  char	*line;

  if ((fd = open(".p_command.hst", O_RDWR | O_CREAT, 0644 | O_DIRECTORY)) == -1)
    exit(1);
  utils->history_len = 0;
  utils->position = NULL;
  utils->com_history = NULL;
  utils->com_history_end = NULL;
  utils->com_history_start = NULL;
  while (get_next_line(fd, &line))
  {
    new_hlist(line, utils);
    free(line);
  }
  free(line);
  close(fd);
}

void		init_utils(t_utils *utils, t_parsing *parsing, char **env)
{
  utils->pwd = find_in_env(env, "PWD");
  utils->oldpwd = find_in_env(env, "OLDPWD");
  utils->parsing_start = parsing;
  get_command_file(utils);
  g_sig.pid = -1;
  utils->fdin[0] = 0;
  utils->fdin[1] = 1;
  utils->fdout[0] = 0;
  utils->fdout[1] = 1;
  utils->savefd = -1;
  utils->savefdout = -1;
  utils->return_value = 0;
  g_sig.prefix = 0;
}

void		write_down_cfile(t_utils *utils, int fd)
{
  t_historical *histo;

  histo = utils->com_history_start;
  if (histo->command != NULL)
  {
    ft_putstr_fd(histo->command, fd);
    ft_putchar_fd(10, fd);
    while (histo->next != NULL)
    {
      histo = histo->next; 
      if (histo->command != NULL)
      {
	ft_putstr_fd(histo->command, fd);
	ft_putchar_fd(10, fd);
      }
    }
  }
}

void		put_histo_in_file(t_utils *utils)
{
  int	fd;

  if ((fd = open(".p_command.hst", O_RDWR | O_CREAT, 0644 | O_DIRECTORY)) == -1)
    exit(1);
  if (utils->com_history_start->command != NULL)
    write_down_cfile(utils, fd);
  close(fd);
}

int		main(int argc, char **argv, char **env)
{
  char			*line;
  t_parsing		*parsing;
  int				i;
  static t_utils	utils;

  ft_signal();
  parsing = new_list(NULL);
  init_utils(&utils, parsing, env);
  utils.line_p = &line;
  argc = 0;
  argv = NULL;
  utils.tmp = malloc(sizeof(char*) * (ft_doubletab_len(env) + 1));
  recopy_data(utils.tmp, env, 0);
  env = utils.tmp;
  i = 0;
  line = NULL;
  g_sig.pid = -1;
  ft_print_prefix(0, &env, &utils);
  if (term_init(&utils))
  {
    while (shelline_gestion(&env, &utils, &line) > 0)
    {
      i = recursive_parsing(&line, parsing, i);
      while (i == OPEN_SQUOTE || i == OPEN_DQUOTE)
	get_open_quote(&i, &line, ft_last_pars(parsing), &utils);
      if (!ft_sep(*parsing))
	fonction_router(parsing, &env, &utils);
      parsing = new_list(parsing);
      i = 0;
      free(line);
      line = NULL;
      g_sig.pid = -1;
    }
    if (line != NULL)
      free(line);
    line = NULL;
    tcsetattr(0, 0, &utils.s_termios_backup);
    ft_putstr_fd("exit\n", 1);
  }
  else
  {
    ft_putstr_fd("termcaps init fail\n", STDERR_FILENO);
    ft_exit(&env, &utils, 1);
  }
  ft_exit(&env, &utils, 0);
  return (0);
}
