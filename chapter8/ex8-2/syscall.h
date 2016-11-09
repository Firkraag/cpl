#include <unistd.h>

#undef NULL
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

struct _flags {
    unsigned _READ : 1;
    unsigned _WRITE : 1;
    unsigned _UNBUF : 1;
    unsigned _EOF : 1;
    unsigned _ERR : 1;
};

typedef struct _iobuf {
	int cnt;
	char *ptr;
	char *base;
	struct _flags flag;
	int fd;
} FILE;


extern FILE _iob[OPEN_MAX];
int _fillbuf(FILE *);
int _flushbuf(int, FILE *);

#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

#define feof(p)		((p)->flag._EOF)
#define ferror(p)	((p)->flag._ERR)
#define fileno(p)	((p)->fd)

#define getc(p)		(--(p)->cnt >= 0 \
				?	(unsigned char) *(p)->ptr++ : _fillbuf(p))
#define putc(x, p)		(--(p)->cnt >= 0 \
				?	*(p)->ptr++ = (x) : _flushbuf((x), p))

#define getchar()	getc(stdin)
#define putchar(x)	putc((x), stdout)

FILE *fopen(char *, char *);
