/*************************************************************************
	> File Name: test.c
	> Author: 
	> Mail: 
	> Created Time: Fri 04 Nov 2016 09:20:53 PM CST
 ************************************************************************/

#include "syscall.h"

int main(int argc, char *argv[]) {
    FILE *fp;
    int c;

    if (argc == 1) {
        while ((c = getchar()) != EOF)
        {
//            putchar(c);
            putc(c, stderr);
        }
    }
	else
    {
        while (--argc > 0) {
            fp = fopen(*++argv, "r");
            if (fp == NULL)
                return 0;
            while ((c = getc(fp)) != EOF)
                putchar(c);
            fclose(fp);
        }
    }
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    
	return 0;
}

