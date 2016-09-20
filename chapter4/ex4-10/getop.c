#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXLINE 80

int getline2(char *s, int length);

/* getop: get next character or numeric operand */
int getop(char s[])
{
    static char line[MAXLINE];//Global variables and static variables are automatically initialized to zero
    static int index = 0;
    int i, c;

    if (line[index] == '\0') {
        if (getline2(line, MAXLINE) == 0) 
            return EOF;
        else
            index = 0;
    }
    while ((s[0] = c = line[index++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (c == '\0') {
        index--;
        return '\n';
    }
    else if (c == '-') {
        s[++i] = c = line[index++];
        if (!isdigit(c) && c != '.') {
            index--;
            return '-';
        }
    }
    else if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = line[index++]))
        ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = line[index++]))
        ;
    s[i] = '\0';
    index--;
    return NUMBER;
}

int getline2(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
