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
    int *data;
    int length;
    int index;

};
typedef struct dynamicList DL;
//build a dynamic list
DL *initDL();
//free the resources used by the dynamic list
void freeDL(DL *dl);
void expandSize(DL *dl);
void append(DL *dl, int number);
int size(DL *dl);
int *content(DL *dl);

