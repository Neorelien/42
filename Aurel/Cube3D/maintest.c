#include "Cube3D_utils.h"

int main()
{	
	int fd;
	char **line;

	fd = open("map.cub", O_RDONLY);
	*line = malloc(sizeof(char*));
	get_next_line(fd, line);
	printf("%s", *line);
}
