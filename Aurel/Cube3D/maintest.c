#include "Cube3D_utils.h"

int main()
{	
	int fd;
	int fd2;
	char **line;

	fd = open("map.cub", O_RDONLY);
	fd2 = open("m.cub", O_RDONLY);
//	get_next_line(fd, line);
	printf("%d\n", fd);
	printf("%d", fd2);
}
