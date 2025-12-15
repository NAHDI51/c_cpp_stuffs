#include <stdio.h>
#include <ctype.h>

int hash1(char c) {return (toupper(c) == 'B') ? 0 : 1;}
int hash2(char c) {
	c = toupper(c);
	if(c == 'L') return 0;
	else if(c == 'T') return 1;
	else if(c == 'D') return 2;
}

int main() {
	double price[2][3] = {{0.75, 1.00, 1.25}, {1.25, 2.00, 2.75}};

	char a[2], b[2];
	printf("Type of print: ");
	scanf("%s", a);
	printf("Type of paper: ");
	scanf("%s", b);

	int amount;
	printf("Number of papers per day: ");
	scanf("%d", &amount);

	double p = price[hash1(a[0])][hash2(b[0])];
	printf("Monthly Bill: %0.2lf * %d * %d = %0.2lf\n", p, amount, 30, p*(double)(amount*30));
}