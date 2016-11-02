#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define NUMBER '0'
#define MAXLINE 8096

int getch(void);
void ungetch(int);

//int getch(void);
//void ungetch(int);
/* getop: get next character or numeric operand */
int getop(float *ptr)
{
	static char word[MAXLINE] = {'\0'};
	static int offset = 0;
    static int length = 0;
	int c;


	if (offset >= length) {
		c = scanf("%s", word);
		if (c == EOF)
			return EOF;
        else {
            offset = 0;
            length = strlen(word);
        }
	}
	c = word[offset];
	if (!isdigit(c) && c != '.') {
		offset++;
		return c;
	}

	sscanf(word + offset, "%f", ptr);
    if (isdigit(c)) /* collect integer part */
        while (offset < length && isdigit(c = word[++offset]))
            ;
    if (c == '.') /* collect fraction part */
        while (offset < length && isdigit(c = word[++offset]))
            ;
	return NUMBER;
}
