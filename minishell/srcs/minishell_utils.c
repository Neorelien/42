#include "../minishell_utils.h"

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

int	write_with_separator(t_parsing info)
{
	int sep;
	int fd;

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
		if (fd < 0);
			ft_error(strerror(errno), info.next->objet);
		return (fd);
	}
}

int	ft_error(char *str, char *strbis)
{
	ft_putstr_fd(str, 1);
	if (strbis != NULL)
		ft_putstr_fd(strbis, 1);
	ft_putchar_fd('\n', 1);
	return (-1);
}
