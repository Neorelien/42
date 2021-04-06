#include "../minishell_utils.h"

void	ft_print_prefix(int	activate, char ***env, t_utils *utils)
{
	static char		***env_stat;
	static t_utils	*utils_stat;
	char	*prefix;
	char	*tmp;

	if (activate)
	{
		ft_putstr_fd("\n", 1);
		prefix = ft_display_rep(*env_stat, *utils_stat);
		tmp = prefix;
		prefix = ft_strjoin(prefix, "-> ");
		free(tmp);
		tmp = ft_strdup("");
		refresh_screen(NULL, NULL, NULL);
		refresh_screen(&tmp, prefix, utils_stat);
		free(tmp);
		free(prefix);
	}
	else
	{
		env_stat = env;
		utils_stat = utils;
	}
}


void handler_next(int sign)
{
	if (g_sig.pid == -1)
	{
		(void)sign;
		g_sig.prefix = -1;
		ft_print_prefix(1, NULL, NULL);
	}
	else
	{
		ft_putstr_fd("\n", 1);
	}
}

void handler_quit(int sign)
{
	if (g_sig.pid != -1)
		printf("Quit: %d\n", sign);
}

char *find_in_env(char **env, char *name)
{
	unsigned int i;
	char *path;
	char *tmp;

	i = 0;
	while (!ft_isspace(name[i]) && name[i])
		i++;
	path = ft_substr(name, 0, i);
	tmp = ft_strjoin(path, "=");
	free(path);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(tmp, env[i], ft_strlen(tmp) - 1) == 0)
		{
			path = ft_strdup(env[i] + ft_strlen(tmp));
			free(tmp);
			return (path);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}

size_t ft_doubletab_len(char **doubletab)
{
	int	i;
	i = 0;
	if (doubletab == NULL)
		return (0);
	while (doubletab[i])
		i++;
	return (i);
}

int		is_separator_parsing(char *str, int i)
{
	if (i > 0)
	{
		if (str[i] == ';' && str[i - 1] != 92)
			return (1);
		if (str[i] == '|' && str[i - 1] != 92)
			return (2);
		if (str[i] == '<' && str[i - 1] != 92)
			return (4);
		if (str[i] == '>' && str[i + 1] == '>' && str[i - 1] != 92)
			return (5);
		if (str[i] == '>' && str[i - 1] != 92)
			return (3);
	}
	else
	{
		if (str[i] == ';')
			return (1);
		if (str[i] == '|')
			return (2);
		if (str[i] == '>')
			return (3);
		if (str[i] == '<')
			return (4);
		if (str[i] == '>' && str[i + 1] == '>')
			return (5);
	}
	return (0);
}

int		is_separator(char *str)
{
	if (str[0] == ';' && str[1] == 0)
		return (1);
	if (str[0] == '|' && str[1] == 0)
		return (2);
	if (str[0] == '>' && str[1] == 0)
		return (3);
	if (str[0] == '<' && str[1] == 0)
		return (4);
	if (str[0] == '>' && str[1] == '>' && str[2] == 0)
		return (5);
	return (0);
}

int			ft_lstsize(t_parsing *lst)
{
	int size;

	size = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

t_parsing	*ft_lstlast(t_parsing *lst)
{
	while (lst->next != NULL)
		lst = lst->next; 
	return (lst);
}

void			ft_pipe_settings(t_utils *utils)
{	
	pipe(utils->fdout);
	if (utils->savefd == -1)
		utils->savefd = dup(1);
	dup2(utils->fdout[1], 1);
	close(utils->fdout[1]);
}

void ft_env_fd(t_parsing *info, char **env)
{
	char *tmp;

	if (info->next != NULL && info->next->objet[0] == '$')
	{
		tmp = info->next->objet;
		info->next->objet = find_in_env(env, info->next->objet + 1);
		free(tmp);
	}
}

void	check_to_next(t_parsing info, char ***env, t_utils *utils)
{
	if (is_separator(info.separator) == 0 || is_separator(info.separator) == 2)	
		return ;
	if (is_separator(info.separator) == 1)
		fonction_router(info.next, env, utils);
	else
	{
		check_to_next(*info.next, env, utils);
	}
}

int		ft_next_is_pipe(t_parsing info, char **env, t_utils *utils, int flag)
{
	if (is_separator(info.separator) == 0 || is_separator(info.separator) == 1)
		return (flag);
	if (is_separator(info.separator) == 2)
		return (1);
	else
		flag = ft_next_is_pipe(*info.next, env, utils, flag);
	return (flag);
}

void ft_reroll(t_parsing info, char **env, t_utils *utils)
{
	char tmp_sep[3];
	t_parsing *tmp_next;

	if ((info.data == NULL || info.data[0] == NULL) && utils->data != NULL)
		info.data = utils->data;
	tmp_sep[0] = info.next->separator[0];
	tmp_sep[1] = info.next->separator[1];
	tmp_sep[2] = info.next->separator[2];
	tmp_next = info.next->next;
	info.next->separator[0] = 0;
	info.next->separator[1] = 0;
	info.next->separator[2] = 0;
	info.next->next = NULL;
	fonction_router(&info, &env, utils);
	info.next->separator[0] = tmp_sep[0];
	info.next->separator[1] = tmp_sep[1];
	info.next->separator[2] = tmp_sep[2];
	info.next->next = tmp_next;
	utils->data = info.data;
}



int	write_with_separator(t_parsing info, char **env, t_utils *utils, int fd)
{
	int sep;
	int flag_pipe;

	flag_pipe = ft_next_is_pipe(info, env, utils, 0);
	if ((sep = is_separator(info.separator)) == 0 || sep == 1)
		return (fd);
//	else if (sep == 2)
//		return (ft_pipe_settings(info, env, utils));
	else if (sep == 3)
	{
		if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
			ft_reroll(info, env, utils);
		else
		{
			fd = open(info.next->objet, O_WRONLY | O_TRUNC | O_CREAT, 0644 | O_DIRECTORY);
			if (fd < 0)
				ft_error(strerror(errno), info.next->objet);
		}
		fd = write_with_separator(*info.next, env, utils, fd);
	}
	else if (sep == 4)
		fd = write_with_separator(*info.next, env, utils, fd);
	else if (sep == 5)
	{
		if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
			ft_reroll(info, env, utils);
		else
		{
			fd = open(info.next->objet, O_RDWR | O_APPEND | O_CREAT, 0644 | O_DIRECTORY);
			if (fd < 0)
				ft_error(strerror(errno), info.next->objet);
		}
		fd = write_with_separator(*info.next, env, utils, fd);
	}
	return (fd);
}

int	ft_error(char *str, char *strbis)
{
	ft_putstr_fd(str, 1);	
	if (strbis != NULL)
	{
		ft_putstr_fd(": ", 1);
		ft_putstr_fd(strbis, 1);
	}
	ft_putchar_fd('\n', 1);
	return (1);
}

int reset_fd_one(t_utils *utils)
{
	if (utils->savefd != -1)
	{
		close(utils->redir);
		dup2(utils->savefd, utils->redir);
		utils->savefd = -1;
		utils->redir = 1;
		return (1);
	}
	return (0);
}

int reset_fd_zero(t_utils *utils)
{
	if (utils->savefdout != -1)
	{
		close(0);
		dup2(utils->savefdout, 0);
		utils->savefdout = -1;
		return (1);
	}
	return (0);
}
