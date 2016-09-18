#include <stdio.h>
#include <string.h>
#define MAXLEN 1000 /* max length of any input line */

int getline1(char *s, int lim) {
	int c;
	char *start = s;
	char *end = s + lim - 1;

	while ((s < end) && ((c = getchar()) != EOF) && (c != '\n'))
		*s++ = c;
	if (c == '\n') 
		*s++ = c;
	*s = '\0';
	return s - start;
} 

/* readlines: read input lines */
/* This procedure store lines in an array supplied by main */
/* Return -1 when too many lines are presented */
/* Return -2 when the array supplied by the main routine is not big enough to hold the input */
/* Otherwise, return number of lines of input */
//We suppose content[sizes] is big enough to hold the input. What will happen if the input is too big is undefined, so be cautious to not exceed the limit
int readlines(char content[], int sizes, char *lineptr[], int maxlines)	{

	int nlines = 0;
	int lineLength = 0;
    char line[MAXLEN], *boundary = content + sizes;

    while ((lineLength = getline1(line, MAXLEN)) > 0) {
        if (nlines >= maxlines)
            return -1;
        else if (content + lineLength >= boundary) {
            return -2;
        }
        else {
            line[lineLength - 1] = '\0';
            strcpy(content, line);
            lineptr[nlines++] = content;
            content += lineLength;
        }
    }
    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines)	{
	int i;

	for (i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}
