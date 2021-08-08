/**********************************************************************************
	> File Name: 7-8.c
	> Author: 
	> Mail: 
	> Created Time: Thu 03 Nov 2016 01:04:34 PM CST
 ************************************************************************/

#include<stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINE 30
#define PAGESIZE 20

void printFile(char *file);
int printTitle(char *title);
void printPageNo(int pageno);
void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        fprintf(stderr, "usage: printFile [file...]\n");
        return 1;
    }
    else {
        for (int i = 1; i < argc; i++) {
            printFile(argv[i]);
        }
    }

}

void printFile(char *file)
{
    FILE *fp = fopen(file, "r");
    char line[MAXLINE];
    int lineno, pageno;

    if (fp == NULL) {
        fprintf(stderr, "Open file %s error\n", file);
        return;
    }
    else {
        lineno = printTitle(file);
        pageno = 1;
    }

    while (fgets(line, MAXLINE, fp) != NULL) {
        fputs(line, stdout);
        if (line[strlen(line) - 1] != '\n')
            putchar('\n');
        if (++lineno == PAGESIZE - 1) {
            printPageNo(pageno++);
            lineno = 0;
        }
    }
    if (lineno > 0)
    {

        while (++lineno < PAGESIZE) {
            putchar('\n');
        }
        printPageNo(pageno);
    }
    fclose(fp);
}

/* print the title and return the number of lines the title used */
int printTitle(char *title) {
    int len = strlen(title);
    char *ptr = title;
    int counter = 0;
    void putsn(char *string, int n);

    while (len >= MAXLINE)
    {
        putsn(ptr, MAXLINE);
        if (ptr[MAXLINE - 1] != '\n')
            putchar('\n');
        counter++;
        len -= MAXLINE;
        ptr += MAXLINE;
    }
    if (len > 0)
    {
        if (counter == 0)
            for (int i = 0; i < (MAXLINE - len) / 2; i++)
                putchar(' ');
        printf("%s", ptr);
        if (ptr[len - 1] != '\n')
            putchar('\n');
        counter++;
    }
    return counter; 
}

/* print at most n character from string */
void putsn(char *string, int n) {
    for (int i = 0; i < n; i++) {
        if (string[i] == '\0')
            return;
        else
            putchar(string[i]);
    }
}

void printPageNo(int pageno) {
    char s[10];
    int len = strlen(s);

    itoa(pageno, s);
    /* print the page number at the center of the line */
    for (int i = 0; i < (MAXLINE - len - 5) / 2; i++)
        putchar(' ');
    printf("Page %s\n", s);
}

void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0) /* record sign */
        n = -n; /* make n positive */
    i = 0;
    do { /* generate digits in reverse order */
        s[i++] = n % 10 + '0'; /* get next digit */
    } while ((n /= 10) > 0); /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
