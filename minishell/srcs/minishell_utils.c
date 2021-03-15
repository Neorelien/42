#include "../minishell_utils.h"

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
			return (path);
		}
		i++;
	}
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

int		ft_pipe_settings(t_parsing info, char **env, t_utils *utils)
{
	pipe(utils->pipefd);
	utils->cpid = fork();
	if (utils->cpid == 0)
	{
		if (utils->pipefd[1] > 0)
			close(utils->pipefd[1]);
		return (utils->pipefd[0]);
	}
	else
	{
		if (utils->pipefd[0] > 0)
			close(utils->pipefd[0]);
		return(utils->pipefd[1]);
	}
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
	echo(info, &env, utils);
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
	else if (sep == 2)
		return (ft_pipe_settings(info, env, utils));
	else if (sep == 3)
	{
		if (flag_pipe == 0 && is_separator(info.separator) != 0 && is_separator(info.next->separator) != 0 && is_separator(info.next->separator) != 1)
			ft_reroll(info, env, utils);
		else
		{
			fd = open(info.next->objet, O_WRONLY | O_CREAT, 0644 | O_DIRECTORY);
			if (fd < 0)
				ft_error(strerror(errno), info.next->objet);
		}
		fd = write_with_separator(*info.next, env, utils, fd);
	}
	else if (sep == 4)
		fd = write_with_separator(*info.next, env, utils, fd);
	else
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
	ft_putstr_fd(": ", 1);
	if (strbis != NULL)
		ft_putstr_fd(strbis, 1);
	ft_putchar_fd('\n', 1);
	return (-1);
}
