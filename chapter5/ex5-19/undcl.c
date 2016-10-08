/*************************************************************************
	> File Name: dcl.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Oct 2016 03:35:22 PM CST
 ************************************************************************/

#include "cpl.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };


int gettoken(void);
void ungettoken(int tokentype);
int tokentype;/* type of last token */
char token[MAXTOKEN];/* last token string */
char out[1000];/* output string */

/* undcl: convert word descriptions to declarations */
int main()
{
    int type;
    char temp[MAXTOKEN];

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken())!= '\n') {
            if (type == '*') {
                int count = 1;
                while ((type = gettoken()) == '*')
                    count++;
                if (type == PARENS || type == BRACKETS) {
                    int i;
                    temp[0] = '(';
                    for (i = 1; i <= count; i++) {
                        temp[i] = '*';
                    }
                    temp[count + 1] = '\0';
                    strcat(temp, out);
                    strcat(temp, ")");
                    strcpy(out, temp);
                }
                else if (type == NAME) {
                    int i;
                    for (i = 0; i < count; i++) {
                        temp[i] = '*';

                    }
                    temp[count] = '\0';
                    strcat(temp, out);
                    strcpy(out, temp);

                }
                ungettoken(type);
            } 
            else if (type == PARENS || type == BRACKETS)
                strcat(out, token);
            else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } 
            else if (type == EOF) {
                ungettoken(type);
                putchar('\n');
                break;
            }
            else
                printf("invalid input at %s\n", token);
        }
        printf("%s\n", out);
    }
    return 0;
}

static int buf[100];
static int sp = 0;

int gettoken(void)/* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (sp > 0)
    {
        return buf[--sp];
    }
  
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } 
        else {
            ungetch(c);
            return tokentype = '(';
        }
    } 
    else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']';)
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } 
    else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch());)
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } 
    else
        return tokentype = c;
}

void ungettoken(int tokentype) {
    buf[sp++] = tokentype;
}

