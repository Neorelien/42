#include "Cube3D_utils.h"

int main()
{	
	int fd;
	char **line;

	fd = open("map.cub", O_RDONLY);
	get_next_line(fd, line);
	printf("%d", fd);
}
