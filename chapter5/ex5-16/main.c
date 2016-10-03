/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:10:47 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *compare[MAXLINES];
char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
/* content is the actual array needed to be sorted, compare is the array to be compared in qsort */
void qsort(void *compare[], void *content[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
void Reverse(void **array, int length);
void dictOrderFilter(char *src[], char *dest[], int lines);
void upper2lower(char *array[], int lines);
void copy(char *src[], char *dest[], int lines);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0; /* 1 if reverse */
    int i;
    int caseSensitive = 1; /* 1 if case sensitive */
    int dictOrder = 0; /* 1 if considr only letters, numbers and blanks */

    /* get option */
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
            case 'f':
                caseSensitive = 0;
                break;
            case 'd':
                dictOrder = 1;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                i = argc + 1;
                break;
            }
        }
    } 
    if (i != argc) {
        printf("Usage: sort [-n] [-r] [-d] [-f]\n");
        return -1;
    }

    /* read lines and sort */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (dictOrder)
            dictOrderFilter(lineptr, compare, nlines);
        else
            copy(lineptr, compare, nlines);
        if (!caseSensitive)
            upper2lower(compare, nlines);
        qsort((void **) compare, (void**) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        if (reverse)
            Reverse((void **) lineptr, nlines);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}
