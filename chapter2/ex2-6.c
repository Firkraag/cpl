#include <stdio.h>
/*returns x with the n bits that begin at position
p set to the rightmost n bits of y, leaving the other bits unchanged.*/
unsigned setbits(unsigned x,int p,int n,unsigned y) {
	unsigned bit = (~0 << (p-n+1)) & ((unsigned) ~0 >> (31-p));
	x  = x & ~bit;
    printf("test 0x%x\n", x);
	y = (y << (p-n+1)) & bit;
    printf("test 0x%x\n", y);
	return x | y;

}
int main() {
	printf("0x%x\n", setbits(0xff,3,3,0x5));
	printf("0x%x\n", setbits(0xff,7,3,0x5));
	printf("0x%x\n", setbits(0xff,2,3,0x5));
}	
	
