/*************************************************************************
	> File Name: dcl.c
	> Author: 
	> Mail: 
	> Created Time: Tue 04 Oct 2016 03:35:22 PM CST
 ************************************************************************/

#include "cpl.h"

#define MAXTOKEN 100


enum { NAME, PARENS, BRACKETS, QUALIFIER };
int isDcl; //When we get a token from function dcl, we set isDcl to 1

void dcl(void);
void dirdcl(void);

int isQualifier(char *str);
int gettoken(void);
void ungettoken(int tokentype);
void clearLine(void);
int tokentype;/* type of last token */
char token[MAXTOKEN];/* last token string */
char name[MAXTOKEN];/* identifier name */
char datatype[MAXTOKEN];/* data type = char, int, etc. */
char out[1000];/* output string */

int main()/* convert declaration to words */
{
    while (gettoken() != EOF) {/* 1st token on line */
        strcpy(datatype, token);/* is the datatype */
        out[0] = '\0';
        dcl();/* parse rest of line */
        if (tokentype != '\n') {
            printf("syntax error\n");
            clearLine();
        }
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

/* dcl: parse a declarator */
void dcl(void)
{
    int i = 0;
    char qualifiers[100][100]; 
    int type;
    char temp[30];

    isDcl = 1;
    while (gettoken() == '*') {
        char *qualifier = qualifiers[i++];
        qualifier[0] = '\0';
        while ((type = gettoken()) == QUALIFIER) {
            sprintf(temp, "%s ", token);
            strcat(qualifier, temp);
        }
        ungettoken(type);
        strcat(qualifier, "pointer to ");
    }

    dirdcl();
    for (int j = i - 1; j >= 0; j--) {
       strcat(out, qualifiers[j]); 
    }
}

/* dirdcl:  parse a direct declarator */
void dirdcl(void)
{
    int type;
    char temp[100];
    
    isDcl = 0;
    if (tokentype == '(') {/* ( dcl ) */
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    } 
    else if (tokentype == NAME)/* variable name */
        strcpy(name, token);
    else
        printf("error: expected name or (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS) {
            sprintf(temp, "function %s returning ", token);
            strcat(out, temp);
        }
        else {
            strcat(out, "array ");
            strcat(out, token);
            strcat(out, "of ");
        }
}

static int buf[MAXTOKEN];
static int sp = 0;

int gettoken(void)/* return next token */
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (sp > 0) 
        return buf[--sp];

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if (isDcl) 
            return tokentype = '(';
        else {
            do {
                *p++ = c;
            } while ((c = getch()) != ')');
            *p++ = ')';
            *p = '\0';
            return tokentype = PARENS;
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
        if (isQualifier(token)) {
            return tokentype = QUALIFIER;
        }
        else {
            return tokentype = NAME;
        }
    }
    else
        return tokentype = c;

}


void ungettoken(int tokentype) {
    buf[sp++] = tokentype;
}

int isQualifier(char *str) {
    return (strcmp(str, "volatile") == 0) || (strcmp(str, "const") == 0);
}

void clearLine(void) {
    int c;
    while (((c = getch()) != EOF) && (c != '\n'))
        ;
    if (c == EOF)
        ungetch(c);
}
