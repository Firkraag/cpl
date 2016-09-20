#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'


/* getop: get next character or numeric operand */
int getop(char s[])
{
    static int buffer;
    static int getFromBuffer = 0;
    int i, c;

    if (getFromBuffer) {
        s[0] = c = buffer;
        getFromBuffer = 0;
    }
    else {
        s[0] = c = getchar();
    }
    if (c == ' ' || c == '\t')
        while ((s[0] = c = getchar()) == ' ' || c == '\t')
            ;
    s[1] = '\0';
    i = 0;
    if (c == '-') {
        s[++i] = c = getchar();
        if (!isdigit(c) && c != '.') {
            buffer = c;
            getFromBuffer = 1;
            return '-';
        }
    }
    else if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getchar()))
        ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getchar()))
        ;
    s[i] = '\0';
    buffer = c;
    getFromBuffer = 1;
    return NUMBER;
}
