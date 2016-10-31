/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 10:05:11 PM CST
 ************************************************************************/

#include "preProcessor.h"

int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char *name = NULL, *replace = NULL;

    while ((len = getline2(line, MAXLINE)) > 0) {
        if (parseLine(line, &name, &replace))
        {
            install(name, replace);
            free(name);
            free(replace);
        }
    }
    printTable();
    freeTable();
}
