/*************************************************************************
	> File Name: fputs.c
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Nov 2016 12:09:29 PM CST
 ************************************************************************/

#include "syscall.h"

int fputs(const char *s, FILE *fp) 
{
    int c;

    while ((c = *s++) != '\0')
        if (putc(c, fp) == EOF)
            return EOF;
    return 0;
}

int puts(const char *s) 
{
    if (fputs(s, stdout) == EOF)
        return EOF;
    else if (putchar('\n') == EOF) {
        return EOF;
    }
    else 
        return 0;
}
