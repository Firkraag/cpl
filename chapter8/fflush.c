#include <unistd.h>
#include "syscall.h"

static int flushOutput(FILE *fp);
static int flushInput(FILE *fp);

int fflush(FILE *fp) {
    /* If fp is NULL, flush all open output streams */
    if (fp == NULL)
    {
        int ret = 0;

        for (int i = 0; i < OPEN_MAX; i++) {
            FILE *fp = _iob + i;
            if (fp->flag._WRITE) {
                if (flushOutput(fp) == EOF)
                    ret = EOF;
            }
        }
        return ret;
    }
	else if (fp->flag._WRITE) 
    {
        return flushOutput(fp);
	}
    /* Discard all buffered data that has been fetcted from the underlying file, but has not been consumed by the applicaton */
	else if (fp->flag._READ) {
        return flushInput(fp);
	}
	return 0;
}


static int flushOutput(FILE *fp)
{
    int bufsize = (fp->flag._BUFTYPE == UNBUF) ? 1 : BUFSIZ;
    int length = fp->ptr - fp->base;
    if (write(fp->fd, fp->base, length) != length) {
        fp->flag._ERR = 1;
        return EOF;
    }
    else {
        fp->ptr = fp->base;
        fp->cnt = bufsize;
        return 0;
    }
}

static int flushInput(FILE *fp) {
    fp->ptr = fp->base;
    fp->cnt = 0;
    return 0;
}
