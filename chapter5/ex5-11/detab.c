/*************************************************************************
	> File Name: ex1-20.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Aug 2016 08:23:03 AM CST
 ************************************************************************/

#include "cpl.h"

#define TABSTOP 4 

void error(void);
int isNumber(char *string);


int main(int argc, char *argv[])
{
    int c;
    int pos = 0;
    int tab;

    if (argc == 1)
        tab = TABSTOP;
    else if (argc == 2) {
        char *string = argv[1];
        if (isNumber(string)) {
            tab = atoi(string);
        }
        else {
            error();
        }
    }
    else {
        error();
    }

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            pos = 0;
        }
        else if (c == '\t') {
            for (int i = pos; i < tab; i++)
                putchar(' ');
            pos = 0;
        }
        else {
            putchar(c);
            pos = (pos + 1) % tab;
        }
    }
}

void error() {
    printf("Usage: detab [tabstop]\n");
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
