#include "../minishell_utils.h"
#include "libft/libft.h"
char **g_envv;

int main(int argc, char **argv, char **envv)
{
	char *lol;
int i, j;
i = 0;
j = 0;
	while (envv[i])
{
	if (ft_strncmp(envv[i], "HOME=", 4) == 0)
	{
		while (envv[i][j] != '=')
			j++;
		lol = envv[i] + j + 1;
		printf("%s\n", lol);
	}
	i++;
}

/*	t_parsing info;

	info.option = (char**)malloc(sizeof(char*) * 2);
	info.option[0] = (char*)malloc(sizeof(char) * 3);
	info.data = (char**)malloc(sizeof(char*) * 3);
	info.data[0] = (char*)malloc(sizeof(char) * 12);
	info.data[1] = (char*)malloc(sizeof(char) * 17);

	info.option[0] = "-n";
	info.option[1] = NULL;
	info.data[0] = "lol sku sky";
	info.data[1] = "lil peep can fly";
	info.data[2] = NULL;

	echo(info);*/

//	free(info.data[2]);
//	free(&info.data[1]);
//	free(&info.data[0]);
//	free(info.data);
//	free(info.option);

}
