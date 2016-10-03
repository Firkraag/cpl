/*************************************************************************
	> File Name: option.c
	> Author: 
	> Mail: 
	> Created Time: Mon 03 Oct 2016 12:00:13 PM CST
 ************************************************************************/

#include "sort.h"

void setOption(int *option, int mask) {
    *option |= mask;

}

int getOption(int option, int mask) {
    return (option & mask) == mask;
}

int isDictOrder(int c) {
    return isspace(c) || isalnum(c);
}
