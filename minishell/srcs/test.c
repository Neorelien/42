#include "../minishell_utils.h"
#include "libft/libft.h"
#include "errno.h"

int main(int argc, char **argv, char **env)
{
	//printf("%d\n", ft_strncmp("lol", "lol", 400));
	printf("%c\n", -1);
/*	int fd;
	fd = open(argv[1], O_RDWR | O_CREAT, S_IROTH | O_DIRECTORY);
	if (fd < 0)
	{
		printf("%s\n", strerror(errno));
	}*/
/*	char *home_path;
	int i;
	int j;

	i = 0;
	j = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (-1);
*/
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
