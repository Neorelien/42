#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <dirent.h>
int main()
{
	struct dirent lol;
	int fdd;
	DIR fd;
	int pipefd[2];
	fdd = open("lol", O_RDWR | O_CREAT, 0644 | O_DIRECTORY);
	fd = (int)fdd;
	lol = *readdir(&fd);
	printf("%s\n", lol.d_name);
//	printf("%d\n", isatty(pipefd[0]));
//	printf("%s\n", ttyname(fd));
//	printf("%d\n", isatty(fd));
}
