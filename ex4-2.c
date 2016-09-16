#include <stdio.h>
#include <ctype.h>
#include <math.h>

double decimal(char s[], int *index); 
int integer(char s[], int *index);

/* atof: convert string s to double */
double atof(char s[])	{
	double val;
	int i;
    
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
    val = decimal(s, &i);
	if (s[i] == 'e' || s[i] == 'E') {
		i++;
        return val * pow(10, integer(s, &i));
    }
    else {
        return val;
    }
}

/* convert s to integer, starting at position dereferenced by index. Before return,
 * assign one position past the integer to the variable dereferenced by index */
int integer(char s[], int *index) {
    int i = *index, sign;
    int val;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
    for (val = 0; isdigit(s[i]);i++)
        val = 10 * val + (s[i] - '0');
    *index = i;
    return sign * val;
}

/* convert s to decimal, starting at position dereferenced by index. Before return,
 * assign one position past the decimal to the variable dereferenced by index */
double decimal(char s[], int *index) {
    int i = *index, sign;
    double val, power;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
    *index = i;
    return sign * val / power;
}

int main(int argc, char *argv[]) {
	printf("%f\n", atof(argv[1]));
}
