/*************************************************************************
	> File Name: cpl/chapter8/ex8-4.c
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Nov 2016 07:59:22 PM CST
 ************************************************************************/

#include "syscall.h"
#include <sys/types.h>
#include <unistd.h>

int fseek(FILE *fp, long offset, int origin) {
    /* origin must be equal to SEEK_SET, SEEK_CUR, or SEE_END */
    if (origin != SEEK_SET && origin != SEEK_CUR && origin != SEEK_END)
        return -1;

    /* flush buf */
    if (fflush(fp) == EOF)
        return -1;

    /* Clear end-of-file indicator */
    fp->flag._EOF = 0;

    if (lseek(fp->fd, offset, origin) >= 0)
        return 0;
    else
        return -1;
        
}
