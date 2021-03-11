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

void	check_to_next(t_parsing info, char ***env, t_utils *utils)
{
	if (is_separator(info.separator) == 0 || is_separator(info.separator) == 2)
		return ;
	if (is_separator(info.separator) == 1)
		fonction_router(info.next, env, utils);
	else
		check_to_next(*info.next, env, utils);
}

void	ft_next_is_pipe(t_parsing info, char ***env, t_utils *utils)
{
	if (is_separator(info.separator) == 0 || is_separator(info.separator) == 1)
		return ;
	if (is_separator(info.separator) == 2)
		fonction_router(info.next, env, utils);
	else
		ft_next_is_pipe(*info.next, env, utils);
}

int		is_separator_parsing(char *str, int i)
{
	if (i > 0)
	{
		if (str[i] == ';' && str[i - 1] != 92)
			return (1);
		if (str[i] == '|' && str[i - 1] != 92)
			return (2);
		if (str[i] == '>' && str[i - 1] != 92)
			return (3);
		if (str[i] == '<' && str[i - 1] != 92)
			return (4);
		if (str[i] == '>' && str[i + 1] == '>' && str[i - 1] != 92)
			return (5);
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

int	write_with_separator(t_parsing info, char **env, t_utils *utils)
{
	int sep;
	int fd;

	ft_env_fd(&info, env);
	if ((sep = is_separator(info.separator)) == 0 || sep == 1)
		return (1);
	else if (sep == 2)
		return (ft_pipe_settings(info, env, utils));
	if (sep == 3)
	{
		fd = open(info.next->objet, O_RDWR | O_CREAT, 0644 | O_DIRECTORY);
		if (fd < 0)
			ft_error(strerror(errno), info.next->objet);
		return (fd);
	}
	else if (sep == 4)
		return (1);
	else
	{
		fd = open(info.next->objet, O_RDWR | O_CREAT, 0644 | O_DIRECTORY);
		if (fd < 0)
			ft_error(strerror(errno), info.next->objet);
		return (fd);
	}
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
