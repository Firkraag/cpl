#include <unistd.h>

#undef NULL
#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20
#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2
#define FULLBUF 0
#define LINEBUF 1
#define UNBUF 2


struct _flags {
    unsigned _READ : 1;
    unsigned _WRITE : 1;
    unsigned _BUFTYPE : 2;
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
int fseek(FILE *fp, long offset, int origin);
int fflush(FILE *fp);
int _flushbuf(int x, FILE *fp);
char *fgets(char *s, int size, FILE *stream);
int ungetc(int c, FILE *stream);
int getline(char *line, int max);
FILE *fopen(char *, char *);
int fclose(FILE *fp);
int fputs(const char *s, FILE *fp);
int puts(const char *s);
int putc(int c, FILE *fp);


#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define stderr (&_iob[2])

#define feof(p)		((p)->flag._EOF)
#define ferror(p)	((p)->flag._ERR)
#define fileno(p)	((p)->fd)

#define getc(p)		(--(p)->cnt >= 0 \
				?	(unsigned char) *(p)->ptr++ : _fillbuf(p))
//#define putc(x, p) (((--(p)->cnt < 0) || (((p) == stdout) && ((x) == '\n')))  ?	_flushbuf((x), p) : (*(p)->ptr++) = (x))

#define getchar()	getc(stdin)
#define putchar(x)	putc((x), stdout)

