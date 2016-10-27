/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Oct 2016 09:34:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);

struct tnode { 
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}
