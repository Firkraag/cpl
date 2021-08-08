#include <stdio.h>
#include <limits.h>

//Determine the ranges of char, short, int, and long variables, both signed and unsigned
int main() {
    union {
        int i;
        float f;
    } tmp1;
    union {
        long long l;
        double d;
    } tmp2;
	printf("Maximum value of type signed char is %d\n", SCHAR_MAX);
	printf("Minimum value of type signed char is %d\n", SCHAR_MIN);
	printf("Maximum value of type unsigned char is %u\n", UCHAR_MAX);
	printf("Maximum value of type signed short is %d\n", SHRT_MAX);
	printf("Minimum value of type signed short is %d\n", SHRT_MIN);
	printf("Maximum value of type unsigned short is %u\n", USHRT_MAX);
	printf("Maximum value of type signed int is %d\n", INT_MAX);
	printf("Minimum value of type signed int is %d\n", INT_MIN);
	printf("Maximum value of type unsigned int is %u\n", UINT_MAX);
	printf("Maximum value of type signed long is %ld\n", LONG_MAX);
	printf("Minimum value of type signed long is %ld\n", LONG_MIN);
	printf("Maximum value of type unsigned long is %lu\n", ULONG_MAX);
    tmp1.i = 0x7f7fffff;
	printf("Maximum value of type float is %f\n", tmp1.f);
    tmp1.i = 0xff7fffff;
	printf("Minimum value of type float is %f\n", tmp1.f);
    tmp2.l = 0x7fefffffffffffff;
	printf("Maximum value of type double is %f\n", tmp2.d);
    tmp2.l= 0xffefffffffffffff;
	printf("Minimum value of type double is %f\n", tmp2.d);
    return 0;
}


