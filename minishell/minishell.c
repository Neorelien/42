/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awery <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:25:08 by awery             #+#    #+#             */
/*   Updated: 2021/03/22 13:35:26 by awery            ###   ########.fr       */
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
  recopy_data(parsing->data, tmp);
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
  char		*tmp;
  char		to_join[2];
  static char	quote;

  if (line[0][i])
    res = selec_dest(parsing, quote);
  to_join[1] = 0;
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
  if (quote == 39)
    return (OPEN_SQUOTE);
  if (quote == 34)
    return (OPEN_DQUOTE);
  return (i);
}

t_parsing *new_list(t_parsing *previous_lst)
{
  t_parsing	*parsing;

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

char	**recopy_data(char **data, char **temp)
{
  int	i;

  i = 0;
  while (temp[i] != NULL)
  {
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
  else if (line[0][i])
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

int		clean_parsing(t_parsing *parsing)
{
  int i;
  int ex;

  i= 0;
  ex = 0;
  if (parsing->objet != NULL)
  {
    if (ft_strncmp(parsing->objet, "exit", 5) == 0)
      ex = 1;
    free(parsing->objet);
  }
  while (parsing->data != NULL && parsing->data[i] != NULL)
  {
    free(parsing->data[i]);
    i++;
  }
  if (parsing->data != NULL)
    free(parsing->data);
  if (parsing->next != NULL)
    ex = clean_parsing(parsing->next);
  free(parsing);
  return (ex);
}


void	fonction_router(t_parsing *parsing, char ***env, t_utils *utils)
{
  data_formation(parsing, env);
  if (ft_sep(*parsing) <= 0)
    ;
  else if (ft_strncmp(parsing->objet, "echo", 4) == 0)
    ft_echo(*parsing, env, utils);	
  else if (ft_strncmp(parsing->objet, "cd", 2) == 0)
    ft_cd(*parsing, env, utils);
  else if (ft_strncmp(parsing->objet, "pwd", 3) == 0)
    ft_pwd(*parsing, env, utils);
  else if (ft_strncmp(parsing->objet, "export", 6) == 0)
    ft_export(parsing, env, utils);
  else if (ft_strncmp(parsing->objet, "env", 3) == 0)
    ft_env(parsing, *env, utils);
  else if (ft_strncmp(parsing->objet, "unset", 5) == 0)
    ft_unset(parsing, env);
  else if (parsing->objet != NULL)
    ft_other_exc(parsing, *env, utils);
  check_to_next(*parsing, env, utils);
  if (utils->cpid == -2)
    exit(1);
}

void	ft_quit()
{
  if (g_sig.pid != -1)
    printf("[1] %d quit (core dumped) (%s)\n", g_sig.pid, g_sig.objet);
}

int	ft_signal()
{
  signal(SIGINT, handler_next);
  signal(SIGQUIT, ft_quit);
  return (1);
}

void	refresh_screen(char **print, int back)
{
  int	i;

  i = 0;
  if (print[0][0] != 0)
    while (i++ < (int)ft_strlen(*print) - back)
      ft_putchar_fd('\b', 0);
  ft_putstr_fd(*print, 0);
}

int	free_ret(void *to_free)
{
  free(to_free);
  return (1);
}

void	add_to_history(char **line)
{
  if ()
}

int	 ft_recup_line(char **line)
{
  char		buf[2];
  int		ret;
  int		i;
  static int	h_index;

  i = 0;
  buf[1] = 0;
  buf[0] = 0;
  ret = read(0, &buf, 1);
  if (ret != -1 && buf[0] != 0)
  {
    if (buf[0] == 10)
    {
      add_to_hstory(line);
      refresh_screen(line, 0);
      write(0, "\n", 1);
      h_index = -1;
      return (0);
    }
    if (ft_isprint(buf[0]))
    {
  	ft_cpy(line, buf[0]);    
	refresh_screen(line, 1);
    }
    else if (buf[0] == 127)
    {
        if (line[0][0] != 0)
        while (i++ < (int)ft_strlen(*line))
	  ft_putchar_fd('\b', 0);
	line[0][ft_strlen(*line) - 1] = 0;
	ft_putstr_fd(*line, 0);
	write(0, " ", 1);
	ft_putchar_fd('\b', 0);
    }
    h_index = -1;
    if (ret == 0)
      return (-1);
    return (1);
  }
  h_index = -1;
  return (-2);
}

int		shelline_gestion(char **env, t_utils utils, char **line)
{
  int	prefix;
  int	ret;

  prefix = 0;
  ft_signal();
  if (prefix == 0)
  {
    ft_display_rep(env, utils);
    write(0, "-> ", 3);
    *line = ft_strdup("");
    prefix = 1;
  }
  while ((ret = ft_recup_line(line)))
    ;
  prefix = 0;
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

void	get_quote(char **line, int quote)
{
  int	ret;

  free(*line);
  *line = ft_strdup("");
  if (quote == OPEN_DQUOTE)
    write(1, "dquote> ", 8);
  else
    write(1, "quote> ", 8);
  while ((ret = ft_recup_line(line)))
    ;
  if (ret == -1)
    ft_error("unexpected EOF while looking for matching", "\'\"\'");
}

void	get_open_quote(int *i, char **line, t_parsing *parsing)
{
  char *tmp;

  get_quote(line, *i);
  tmp = *line;
  *line = ft_strjoin("\n", *line);
  *i = 0;
  free(tmp);
  *i = recursive_parsing(line, ft_lstlast(parsing), *i);
}

void	init_utils(t_utils *utils, t_parsing *parsing)
{
  utils->pwd = NULL;
  utils->parsing_start = parsing;
  utils->cpid = -1;
}

int		main(int argc, char **argv, char **env)
{
  char			*line;
  t_parsing		*parsing;
  int				i;
  static t_utils	utils;

  parsing = new_list(NULL);
  init_utils(&utils, parsing);
  argc = 0;
  argv = NULL;
  utils.tmp = malloc(sizeof(char*) * (ft_doubletab_len(env) + 1));
  recopy_data(utils.tmp, env);
  env = utils.tmp;
  i = 0;
  line = NULL;
  g_sig.pid = -1;
  if (term_init(&utils))
  {

    while (shelline_gestion(env, utils, &line))
    {	      
      i = recursive_parsing(&line, parsing, i);
      while (i == OPEN_SQUOTE || i == OPEN_DQUOTE)
	get_open_quote(&i, &line, parsing);
      fonction_router(parsing, &env, &utils);
      //	if (clean_parsing(utils.parsing_start))
      //		exit(1);
      //	system("leaks minishell\n");
      parsing = new_list(NULL);
      i = 0;
      free(line);
      g_sig.pid = -1;
    }
    free(line);
    if (tcsetattr(0, 0, &utils.s_termios_backup) == -1)
      return (-1);
    ft_putstr_fd("exit\n", 1);
  }
  ft_putstr_fd("termcaps init fail\n", STDERR_FILENO);
  return (0);
}
