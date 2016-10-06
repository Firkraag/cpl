/*************************************************************************
	> File Name: ex1-21.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 10:47:41 PM CST
 ************************************************************************/

#include "tab.h"

void space2tab(int start, int tabstop);

/* replaces strings of blanks by the minimum number of tabs and blanks
 * to achieve the same spacing
 */
int main(int argc, char *argv[]) {
    int start;
    int tabstop;

    parseArgs(argv, argc, &start, &tabstop);
    if (tabstop <= 0)
    {
        error("Usage: tabstop must be greater than 0");
    }
    space2tab(start, tabstop);
}


void space2tab(int start, int tabstop) {
    int c;
    int pos = 0;

    while ((c = getch()) != EOF) {
        if (c == ' ') {
            int init = pos;
            
            do {
                pos++;
                if (pos >= start && ((pos - start) % tabstop  == 0)) {
                    putchar('\t');
                    init = pos;
                }
            } while ((c = getch()) == ' ');

            ungetch(c);
            for (int i = init + 1; i <= pos; i++) {
                putchar(' ');
            }
        }
        else if (c == '\n')
        {
            putchar('\n');
            pos = 0;
        }
        else if (c == '\t') {
            putchar('\t');
            if (pos < start) {
                pos = start;
            }
            else {
                pos += (tabstop - (pos - start) % tabstop);
            }
        }
        else {
            putchar(c);
            pos++;
        }
    }

}
