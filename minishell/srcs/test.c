#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
	fd = open("lol", O_RDWR |O_CREAT, 0644 | O_DIRECTORY | O_APPEND);
	printf("%d\n", fd);
	write(fd, "lol", 3);
}
