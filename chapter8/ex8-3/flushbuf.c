#include <unistd.h>
#include <stdlib.h>
#include "syscall.h"

int _flushbuf(int x, FILE *fp) {
	int bufsize;

	if ((fp->flag & _WRITE) == 0)
		return EOF;
	if ((fp->flag & _EOF) != 0)
		return EOF;
	if ((fp->flag & _ERR) != 0)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL) {
		if ((fp->base = (char *) malloc(bufsize)) == NULL) {
			return EOF;
		}
		else {
			fp->cnt = bufsize - 1;
			fp->ptr = fp->base;
			return *(fp->ptr)++ = (unsigned char) x;
		}
	}
	else if (write(fp->fd, fp->base, bufsize) != bufsize) {
        fp->flag |= _ERR;
        return EOF;
    }
    else {
        fp->ptr = fp->base;
        fp->cnt = bufsize - 1;
        return *(fp->ptr)++ = (unsigned char) x;
    }
}
