#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char	p[256];

	printf("%zu\n", read(1, &p, 4));
	printf("%s", p);
}
