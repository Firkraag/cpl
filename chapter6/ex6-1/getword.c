/*************************************************************************
 * 
	> File Name: getword.c
	> Author: 
	> Mail: 
	> Created Time: Thu 22 Sep 2016 08:11:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include <ctype.h>

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;

    if (c == '#') {
        while ((c = getch()) != '\n' && c != EOF)
            ;
        if (c == EOF)
            ungetch(c);
        return '#';
    }
    else if (c == '"') {
        while ((c = getch()) != '"') {
            if (c == '\\')
                getch();
        }
        return '"';
    }
    else if (c == '\'') {
        while ((c = getch()) != '\'') {
            if (c == '\\')
                getch();
        }
        return '\'';
    }
    else if (c == '/') {
        c = getch();
        if (c == '/') {
            while ((c = getch()) != '\n' && c != EOF) {

            }
            if (c == EOF)
                ungetch(c);
            return '/';
        }
        else if (c == '*') {
            while (1) {
                c = getch();
                if (c == '*') {
                    c = getch();
                    if (c == '/')
                        return '/';
                }
            }
        }
    }
    else if (!isalpha(c) && (c != '_')) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch()) && (*w != '_')) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
