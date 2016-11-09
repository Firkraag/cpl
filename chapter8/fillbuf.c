#include <unistd.h>
#include <stdlib.h>
#include "syscall.h"

int _fillbuf(FILE *fp) {
	int bufsize;

    if (!fp->flag._READ)
        return EOF;
    if (fp->flag._EOF)
        return EOF;
    if (fp->flag._ERR)
        return EOF;

    if (fp->flag._BUFTYPE == UNBUF) {
        bufsize = 1;
    }
    else
        bufsize = BUFSIZ;

	if (fp->base == NULL)
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0) {
		if (fp->cnt == -1)
            fp->flag._EOF = 1;
		else
            fp->flag._ERR = 1;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}
