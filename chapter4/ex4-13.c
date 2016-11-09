#include <stdio.h>
void swap(char v[], int i, int j) {
	char temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void reverse(int left, int right, char s[]) {
	if (left >= right)
		return;
	else
		reverse(left+1, right-1, s);
	swap(s, left, right);
}

int main(int argc, char *argv[]) {
	char s[20] = "abcdef";
	reverse(0, 5, s);
	printf("%s\n", s);
}

