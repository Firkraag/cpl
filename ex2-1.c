#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <string.h>

int main() {
    int tmp1;
    long long int tmp2;
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
    tmp1 = 0x7f7fffff;
	printf("Maximum value of type float is %f\n", *((float *) &tmp1));
    tmp1 = 0xff7fffff;
	printf("Minimum value of type float is %f\n", *((float *) &tmp1));
    tmp2 = 0x7fefffffffffffff;
	printf("Maximum value of type double is %f\n", *((double *) &tmp2));
    tmp2 = 0xffefffffffffffff;
	printf("Minimum value of type double is %f\n", *((double *) &tmp2));
    return 0;
}


