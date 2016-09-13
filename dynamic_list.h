/*************************************************************************
	> File Name: dynamic_list.h
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2016 11:10:04 AM CST
 ************************************************************************/

#ifndef _DYNAMIC_LIST_H
#define _DYNAMIC_LIST_H
#endif

//predefined size of dynamic list
#define INITLEN 5

struct dynamicList {
    char *data;
    int length;
    //The index of null terminator
    int index;

};
typedef struct dynamicList DL;
//build a dynamic list
DL *initDL();
//free the resources used by the dynamic list
void freeDL(DL *dl);
void expandSize(DL *dl, int newSize);
void append(DL *dl, char *string, int length);
//the string of dl has '\n' before null terminator
int isLine(DL *dl);
int size(DL *dl);
char *content(DL *dl);
//clear the content of the list and set the index to the beginning of the list
void clearContent(DL *dl);

