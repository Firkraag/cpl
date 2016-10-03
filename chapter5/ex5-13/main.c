/*************************************************************************
	> File Name: sort.c
	> Author: 
	> Mail: 
	> Created Time: Mon 19 Sep 2016 01:10:47 AM CST
 ************************************************************************/

#include "cpl.h"

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines);
void error(void);
int isNumber(char *string);

/* sort input lines */
int main(int argc, char *argv[]) {
    int nlines; /* number of input lines read */
    int lines;

    if (argc == 1) {
        lines = 10;
    } 
    else if (argc == 2) {
        char *string = argv[1];
        if ((string[0] == '-') && isNumber(string + 1))
            lines = atoi(string + 1);
        else {
            error();
        }
    }
    else {
        error();
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        if (nlines < lines)
            lines = nlines;
        for (int i = nlines - lines; i < nlines; i++) {
            printf("%s\n", lineptr[i]);
        }
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

void error() {
    printf("Usage: tail [-n]\n");
    exit(1);
}

int isNumber(char *string) {
    int c;
    if (*string == '\0')
        return 0;
    else {
        while ((c = *string++) != '\0') {
            if (!isdigit(c))
                return 0;
        }
        return 1;
    }
}
