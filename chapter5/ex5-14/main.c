/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:10:47 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right,
int (*comp)(void *, void *));
int numcmp(const char *, const char *);
void Reverse(void **array, int length);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0; /* 1 if reverse */
    int i;

    for (i = 1; i < argc && ((argv[i])[0] == '-'); i++) {
        char *string = argv[i];
        int j;
        int c;

        for (j = 1; (c = string[j]) != '\0'; j++) {
            switch(c) {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                i = argc + 1;
                break;
            }
        }
    } 
    if (i != argc) {
        printf("Usage: sort -n -r\n");
        return -1;
    }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort((void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        if (reverse)
            Reverse((void **) lineptr, nlines);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void Reverse(void **array, int length) {
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        void *temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    } 
}
