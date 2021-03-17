#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
#include "../minishell_utils.h"
#include <signal.h>

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

int main()
{
	char *line;
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
