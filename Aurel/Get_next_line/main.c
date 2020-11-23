#include "get_next_line_utils.h"

int main()
{
	char	p[BUFFER_SIZE];
	int		fd;

	fd = open("/Users/Aurelien/Pro/42/Perso/Stud/Aurel/Get_next_line/test", O_RDWR);
	printf("%zu\n", read(fd, &p, BUFFER_SIZE));
	printf("%s", p);
}
