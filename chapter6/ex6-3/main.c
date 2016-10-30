/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Oct 2016 09:34:51 PM CST
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dynamic_list.h"

#define MAXWORD 100

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int binsearch(char *word, char *noise[], int n); 
void free_tree(struct tnode *node);

char *noise[] = {
    "and", "or", "the"
};

#define NWORD (sizeof noise / sizeof(char *))

struct tnode { 
    char *word;
    DL *dl;
    struct tnode *left;
    struct tnode *right;
};
int lineno = 1;

int main()
{
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (word[0] == '\n') {
            lineno++;
        }
        else if (isalpha(word[0]) && binsearch(word, noise, NWORD) < 0)
            root = addtree(root, word);
        
    }
    treeprint(root);
    free_tree(root);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, char *noise[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, noise[mid])) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
