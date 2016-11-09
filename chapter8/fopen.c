#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#include "syscall.h"
#define PERMS 0666




FILE *fopen(char *name, char *mode) {
	int fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
        if (!fp->flag._READ  && !fp->flag._WRITE)
			break;
	if (fp >= _iob + OPEN_MAX)
		return NULL;
	if (*mode == 'w') {
		fd = creat(name, PERMS);
	}
	else if (*mode == 'a') {
		if ((fd = open(name, O_WRONLY, 0)) == -1) {
			fd = creat(name, PERMS);
		}
		lseek(fd, 0L, 2);
	} 
	else {
		fd = open(name, O_RDONLY, 0);
	}
	if (fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
    if (*mode == 'r')
    {
        fp->flag._READ = 1;
        fp->flag._WRITE = 0;
    }
    else {
        fp->flag._READ = 0;
        fp->flag._WRITE = 1;

    }
	return fp;
}
