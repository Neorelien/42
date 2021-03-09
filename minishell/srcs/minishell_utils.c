#include "../minishell_utils.h"

int	ft_isspace_without_back(char c)
{
	if (c == 'n' || c == 't' || c == 'v' || c == 'f' || c == 'r')
		return (1);
	return (0);
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

int	write_with_separator(t_parsing info, char **env)
{
	int sep;
	int fd;
	char *tmp;

	if (info.next != NULL && info.next->objet[0] == '$')
	{
		tmp = info.next->objet;
		info.next->objet = find_in_env(env, info.next->objet + 1);
		free(tmp);
	}
	if ((sep = is_separator(info.separator)) == 0)
		return (1);
	if (sep == 1)
		return (1);
	else if (sep == 2)
		return (1);
	else if (sep == 3)
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
