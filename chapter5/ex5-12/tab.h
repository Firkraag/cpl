/*************************************************************************
	> File Name: tab.h
	> Author: 
	> Mail: 
	> Created Time: Thu 06 Oct 2016 03:40:16 PM CST
 ************************************************************************/

#ifndef _TAB_H
#define _TAB_H
#endif

#include "cpl.h"
#define START 2 /* default value for m */ 
#define TABSTOP 4 /* default value for n */

void parseArgs(char *args[], int size, int *sptr, int *tptr);
void error(char *msg);
int isNumber(char *string);
