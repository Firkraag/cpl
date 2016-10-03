#include "cpl.h"

#define NUMBER '0'


/* getop: get next character or numeric operand */
int getop(char s[], char *arguments[], int size)
{
    //index of argument in arguments
    static int arg_index = 0;
    //index of character in argument
    static int str_index = 0;
    char *argument;
    int i, c;

    if (arg_index >= size) {
        return EOF;
    }

    argument = arguments[arg_index];
    if ((argument[str_index]) == '\0')
    {
        arg_index++;
        if (arg_index >= size)
            return EOF;
        else {
            argument = arguments[arg_index];
            str_index = 0;
        }
    }

    while (isspace((s[0] = c = argument[str_index++])))
            ;
    s[1] = '\0';
    i = 0;
    if (c == '-') {
        s[++i] = c = argument[str_index++];
        if (!isdigit(c) && c != '.') {
            str_index--;
            return '-';
        }
    }
    else if (!isdigit(c) && c != '.')
        return c; /* not a number */

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = argument[str_index++]))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = argument[str_index++]))
            ;
    s[i] = '\0';
    str_index--;
    return NUMBER;
}
