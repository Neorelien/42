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
	printf("\b\blol\n");
//	signal(sign, SIG_IGN);
}

void handler_quit(int sign)
{
	printf("\b\bmdr\n");
//	signal(sign, SIG_DFL);
}

void leave(int sign)
{
	printf("NOO GOD NOOOOO\n");
}

int main()
{
	char *line;
	while (42)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler_quit);
		signal(SIGSTOP, leave);
		get_next_line(0, &line);
		if (ft_strncmp("exit", line, 3) == 0)
			exit(1);
	}
}
