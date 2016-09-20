/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:10:47 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */
#define BUFFERSIZE 100000

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *buffer, int sizes, char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

/* sort input lines */
int main()
{
    int nlines; /* number of input lines read */
    char buffer[BUFFERSIZE];

    if ((nlines = readlines(buffer, BUFFERSIZE, lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
