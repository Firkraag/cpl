/*************************************************************************
 * int
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
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}
