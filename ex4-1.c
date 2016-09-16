#include <stdio.h>
#include <string.h>

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k;
    int index = -1;
    	
	for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0;t[k] != '\0' && s[j] == t[k];j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            index = i;
    }
    return index;
} 	

int main() {
	char s[20] = "abcdfjalfdbadbcfj";
	char t[4] = "abc";
	
	printf("%d\n", strindex(s, t));
}
