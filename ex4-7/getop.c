#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (c == '-') {
        s[++i] = c = getch();
        if (!isdigit(c) && c != '.') {
            ungetch(c);
            return '-';
        }
    }
    else if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
        ;
    s[i] = '\0';
    ungetch(c);
    return NUMBER;
}
