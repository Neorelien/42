#include "../minishell_utils.h"
#include "libft/libft.h"
#include "errno.h"

int main(int argc, char **argv, char **env)
{
	char test[8];
	test[0] = 10;
	test[1] = 0;
	test[2] = 0;

	char test2[8] = "";
	printf("test = %s",test);
/*	int pipefd[2];
	char **buff;
	buff = (char**)malloc(sizeof(char*) * 2);
	*buff = (char*)malloc(sizeof(char) * 3);
	*(buff + 1) = (char*)malloc(sizeof(char) * 3);
	buff[0][0] = '-';
	buff[0][1] = 'e';
	buff[0][2] = '\0';
	pipe(pipefd);
	write(pipefd[1], "lol\n", 4);
printf("%d\n", pipefd[0]);*/
//	buff[1] = pipefd;
//	execve("/bin/cat", buff, env);
	//printf("%d\n", ft_strncmp("lol", "lol", 400));
//	printf("%c\n", -1);
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
