/*************************************************************************
	> File Name: ex1-21.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 10:47:41 PM CST
 ************************************************************************/

#include "cpl.h"

#define TABSTOP 8

void error(void);
int isNumber(char *string);

int main(int argc, char *argv[]) {
    int pos = 0; //The position of current c modulo TABSTOP;
    int c = getchar();
    int start;
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

    //We can use loop invariance to prove that at the start of each iteration, pos equals the position of current c modulo TABSTOP 
    while (c != EOF) {
        if (c == ' ') {
            start = pos;
            while ((c = getchar()) == ' ') {
                pos = (pos + 1) % tab;
                if (pos == 0) {
                    putchar('\t');
                    start = 0;
                }
            }
            pos = (pos + 1) % tab;
            if (pos == 0) {
               putchar('\t'); 
            }
            else {
                for (int i = start; i < pos; i++)
                    putchar(' ');
            }
        }
        else if (c == '\n' || c == '\t') {
            putchar(c);
            c = getchar();
            pos = 0;
        }
        else {
            putchar(c);
            c = getchar();
            pos = (pos + 1) % tab;
        }
    }
}

void error() {
    printf("Usage: entab [tabstop]\n");
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
