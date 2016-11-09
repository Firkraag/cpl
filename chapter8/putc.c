/*************************************************************************
	> File Name: putc.c
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Nov 2016 04:28:22 PM CST
 ************************************************************************/

#include "syscall.h"

/* Return the character written as an unsigned char 
 * cast to an int or EOF on error
 */
int putc(int c, FILE *fp)
{
    if ((fp->cnt <= 0) || ((fp->flag._BUFTYPE == LINEBUF) && (c == '\n')))
    {
        return _flushbuf(c, fp);
    }
    else {
        fp->cnt--;
        return *fp->ptr++ = c;
    }
}
