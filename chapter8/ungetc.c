/*************************************************************************
	> File Name: ungetc.c
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Nov 2016 11:41:55 AM CST
 ************************************************************************/

#include "syscall.h"

int ungetc(int c, FILE *stream) {
    if (stream->base == stream->ptr) {
        return EOF;
    }
    else {
        *(--stream->ptr) = c;
        stream->cnt++;
        return c;
    }
}
