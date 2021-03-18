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
//#include <tcl8.5.h>

void handler(int sign)
{
	ft_putstr_fd("\33[2K\rlol\n", 1);
//	signal(sign, SIG_IGN);
}

void handler_quit(int sign)
{
	printf("mdr\n");
//	signal(sign, SIG_DFL);
}

void leave(int sign)
{
	printf("NOO GOD NOOOOO\n");
	printf("\033[1;31m");
}

int ft_putchar(int c)
{
	int lol = 1;
	write(0, &c, 1); 
	return (lol);
}

int main()
{
	char *line;
	char *term_type = getenv("TERM");
	tgetent(NULL, term_type);
	char *cl_cap = tgetstr("cl", NULL);
	tputs(cl_cap, 1, ft_putchar);
	while (42)
	{
		signal(SIGINT, leave);
		signal(SIGQUIT, handler_quit);

		while (!get_next_line(0, &line))
			;
		if (ft_strncmp("exit", line, 3) == 0)
			exit(1);
		free(line);
	}
}
