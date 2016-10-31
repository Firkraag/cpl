/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 10:05:11 PM CST
 ************************************************************************/

#include<stdio.h>
#include "getline2.h"

struct nlist { /* table entry: */
    struct nlist *prev; /* prev entry in chain */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
};
int parseLine(char *line, char **name, char **replace);
struct nlist *install(char *name, char *defn);
void printTable();
void undef(char *name);

int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */
    char *name = NULL, *replace = NULL;

    while ((len = getline2(line, MAXLINE)) > 0) {
        if (parseLine(line, &name, &replace))
        {
            install(name, replace);
        }
    }
    printTable();
}
