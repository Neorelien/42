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
	signal(sign, SIG_IGN);
}

int main()
{
	char *line;
	while (42)
	{
		signal(SIGINT, handler);
		get_next_line(0, &line);
		if (ft_strncmp("exit", line, 3) == 0)
			exit(1);
	}
}
