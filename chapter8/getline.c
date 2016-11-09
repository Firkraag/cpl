/*************************************************************************
	> File Name: getline.c
	> Author: 
	> Mail: 
	> Created Time: Sat 05 Nov 2016 12:03:32 PM CST
 ************************************************************************/

#include "syscall.h"
#include <string.h>

/* getline: read a line, return length */
int getline(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}
