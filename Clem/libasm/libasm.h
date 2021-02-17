#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

ssize_t ft_write(int fildes, const void *buf, size_t nbyte);

#endif
