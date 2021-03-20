#include "../minishell_utils.h"

int main()
{
	char *line;
	while(1)
	{
		get_next_line(0, &line);
		printf("line = %s\n", line);
	}
}
