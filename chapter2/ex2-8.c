#include <stdio.h>
unsigned rightrot(unsigned x,int n) {
    n = n % 32;
	return (x >> n) | (x << (32 - n));
}
int main() {
	printf("0x%x\n", rightrot(0x7fffffff,0));
	printf("0x%x\n", rightrot(0x7fffffff,4));
	printf("0x%x\n", rightrot(0x7fffffff,32));
	printf("0x%x\n", rightrot(0x7fffffff,33));
}
