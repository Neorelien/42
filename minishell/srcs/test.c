#include "../minishell_utils.h"
#include "libft/libft.h"
int main()
{
	t_parsing info;

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

	echo(info);

//	free(info.data[2]);
//	free(&info.data[1]);
//	free(&info.data[0]);
//	free(info.data);
//	free(info.option);

}
