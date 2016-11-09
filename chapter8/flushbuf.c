#include <unistd.h>
#include <stdlib.h>
#include "syscall.h"

static int fullbuf(int x, FILE *fp);
static int linebuf(int x, FILE *fp);
static int unbuf(int x, FILE *fp);

int _flushbuf(int x, FILE *fp) {
	if (!(fp->flag._WRITE))
		return EOF;
	if (fp->flag._EOF)
		return EOF;
	if (fp->flag._ERR)
		return EOF;

    switch(fp->flag._BUFTYPE) {
    case FULLBUF:
        return fullbuf(x, fp);
        break;
    case LINEBUF:
        return linebuf(x, fp);
        break;
    case UNBUF:
        return unbuf(x, fp);
        break;
    }
    return EOF;
}

static int fullbuf(int x, FILE *fp)
{
    int bufsize = BUFSIZ;

	if (fp->base == NULL) {
		if ((fp->base = (char *) malloc(bufsize)) == NULL) {
			return EOF;
		}
	}
	else if (write(fp->fd, fp->base, bufsize) != bufsize) {
        fp->flag._ERR = 1;
        return EOF;
    }

    fp->ptr = fp->base;
    fp->cnt = bufsize - 1;
    return *(fp->ptr)++ = (unsigned char) x;
}

static int linebuf(int x, FILE *fp)
{
    int bufsize = BUFSIZ;

	if (fp->base == NULL) {
		if ((fp->base = (char *) malloc(bufsize)) == NULL) {
			return EOF;
		}
	}
	else if (write(fp->fd, fp->base, fp->ptr - fp->base) != fp->ptr - fp->base) {
        fp->flag._ERR = 1;
        return EOF;
    }

    if (x != '\n') {
        fp->ptr = fp->base;
        fp->cnt = bufsize - 1;
        return *(fp->ptr)++ = (unsigned char) x;
    }
    else {
        fp->cnt = bufsize;
        fp->ptr = fp->base;
        if (write(fp->fd, "\n", 1) != 1)
        {
            fp->flag._ERR = 1;
            return EOF;
        }
        else
            return '\n';
    }
}

static int unbuf(int x, FILE *fp)
{
    int bufsize = 1;

	if (fp->base == NULL) {
		if ((fp->base = (char *) malloc(bufsize)) == NULL) {
			return EOF;
		}
	}
	else if (write(fp->fd, fp->base, bufsize) != bufsize) {
        fp->flag._ERR = 1;
        return EOF;
    }

    fp->ptr = fp->base;
    fp->cnt = 0;
    return *(fp->ptr)++ = (unsigned char) x;
}
