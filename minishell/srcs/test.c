#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
	int fd;
struct 	stat state;
	fd = open("lol", O_RDWR |O_CREAT, 0644 | O_DIRECTORY | O_APPEND);
	fstat(fd, &state);
	printf("%d\n", state.st_inode);
printf("%llu\n", state.st_size);
printf("%d\n", state.st_blksize);
printf("%d\n", state.st_blocks);
printf("%d\n", state.st_atime);
printf("%d\n", state.st_mtime);
printf("%d\n", state.st_ctime);
}
