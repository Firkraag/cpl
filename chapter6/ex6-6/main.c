/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 10:05:11 PM CST
 ************************************************************************/

#include "preProcessor.h"

int main() {
    char line[MAXLINE]; /* current input line */
    char first[MAXLINE], name[MAXLINE], replace[MAXLINE];

    while (getline2(line, MAXLINE) > 0) {
        /* If the input line has at least three fields and the first field is "#define" */
        if (sscanf(line, "%s %s %s", first, name, replace) == 3 && !strcmp(first, "#define"))
        {
            install(name, replace);
        }
    }
    printTable();
    freeTable();
}
