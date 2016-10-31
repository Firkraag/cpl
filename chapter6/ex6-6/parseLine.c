/*************************************************************************
	> File Name: getword.c
	> Author: 
	> Mail: 
	> Created Time: Mon 31 Oct 2016 10:22:40 AM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <ctype.h>

int delimit(char *string, char *words[], int n);
int getword(char *ptr, char **start, char **end);
//If the first word of the line is "#define", extract name and replace, return 1; otherwise return 0. 
int parseLine(char *line, char **name, char **replace) {
    char *words[3];

    if (delimit(line, words, 3) < 3)
        return 0;
    else if (strcmp(words[0], "#define"))
        return 0;
    else 
    {
        *name = words[1];
        *replace = words[2];
        return 1;
    }
}

/* Extract at most n words from string. 
 * Return the number of words extracted from the string.
 */
int delimit(char *string, char *words[], int n) {
    char *start = NULL;
    char *end = NULL;
    char *ptr = string;
    int c;

    for (int i = 0; i < n; i++) {
        if (!getword(ptr, &start, &end))
            return i;
        else
        {
            c = *(end + 1);
            *(end + 1) = '\0';
            words[i] = strdup(start);
            ptr = end + 1;
            *(end + 1) = c;
        }
    }
    return n;
}
/* Extract first word from string, and fill variables start and end with the start and end of the word. A word is a sequence of characters delimited by spaces. If no word exists, return 0; otherwise return 1
 */
int getword(char *string, char **start, char **end) 
{
    char *ptr = string;
    int c;

    while (isspace(c = *ptr))
        ptr++;

    if (c == '\0')
        return 0;
    else {
        *start = ptr;
        while (!isspace(*ptr) && *ptr != '\0')
            ptr++;
        *end = ptr - 1;
        return 1;
    }
}
