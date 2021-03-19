#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include "../minishell_utils.h"
#include <signal.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <ncurses.h>

t_sig g_sig;

int	alrdy;

void handler_next(int sign)
{
	char 	*printed;
	int		len;

	ft_putstr_fd("\n", 0);
	if (g_sig.pid == -1)
	{
		printed = getenv("PWD");
		len = ft_strlen(printed);
		while (len >= 0 && printed[len] != '/')
			len--;
		printed += len + 1;
		ft_putstr_fd(printed, 0);
		ft_putstr_fd(" -> ", 0);
	}
}

void handler_quit(int sign)
{
	ft_putstr_fd("\n\b\b\b\\b\b  \b\b", 0);
}

int ft_putchar(int c)
{
	int lol = 1;
	write(0, &c, 1); 
	return (lol);
}

int ft_signal()
{
	signal(SIGQUIT, handler_quit);
	while (42);
	return (1);
}

int main()
{
	alrdy = 0;
	char *line;
	g_sig.pid = -1;
	g_sig.pid = fork();
	if (g_sig.pid == 0)
	{
		get_next_line(0, &line);
		printf("%s\n", line);
		free(line);
	}
	else
	{
		ft_signal();
		wait(NULL);
	}
}
