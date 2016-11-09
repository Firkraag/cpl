#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFSIZE 8192

void error(char *fmt, ...);

int main(int argc, char *argv[]) {
	int fd;
    int n;
    char buf[BUFSIZE];

    if (argc == 1) {
        while ((n = read(0, buf, BUFSIZE)) > 0)
            if (write(1, buf, n) != n)
                error("cat: error write to stdout");
    }
	else
    {
		while (--argc > 0)
			if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
				error("cat: can't open %s", *argv);
			}
			else {
                while ((n = read(fd,buf, BUFSIZE)) > 0)
                    if (write(1, buf, n) != n)
                        error("cat: error write to stdout");
				close(fd);
			}

    }
	return 0;
}

/* error: print an error message and die */
void error(char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}


