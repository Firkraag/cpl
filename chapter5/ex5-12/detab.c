/*************************************************************************
	> File Name: ex1-20.c
	> Author: 
	> Mail: 
	> Created Time: Fri 05 Aug 2016 08:23:03 AM CST
 ************************************************************************/

#include "tab.h"

void tab2Space(int start, int tabstop);

/* An detab function that replaces tabs in the input with proper number of blanks to space to the next stop.
 * Tab stops every n columns, starting at column m. If the tab stop is at column less than m, it will expand to column m.
 * When m = 0, the argument m has no effect and tab stops every n columns
 * When n = 0, this function removes all the tabs in the input 
 * The valid command invoked from the shell is detab [-start] [+tabstop] */
int main(int argc, char *argv[])
{
    int start, tabstop;

    parseArgs(argv, argc, &start, &tabstop);
    tab2Space(start, tabstop);
}



/* read from standard input, convert tab to proper number of spaces, then write to standard output */
void tab2Space(int start, int tabstop) {
    int pos = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            pos = 0;
        }
        else if (c == '\t') {
            int numOfSpace;

            if (pos  < start) {
                numOfSpace = start - pos;
                pos = start;
            }
            else {
                if (tabstop == 0)
                    numOfSpace = 0;
                else
                    numOfSpace = tabstop - ((pos - start) % tabstop);
                pos += numOfSpace;
            }
            for (int i = 0; i < numOfSpace; i++)
                putchar(' ');
        }
        else {
            putchar(c);
            pos++;
        }
    }

}


