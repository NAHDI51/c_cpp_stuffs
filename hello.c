#include<stdio.h>
#include<ctype.h>

int main()
{
	char up_in, lo_in, up_out, lo_out;

	printf("Enter lowercase character: ");
	scanf(" %c", &lo_in);
	lo_out = toupper(lo_in);
	printf("Lowercase to uppercase: %c\n", lo_out);

	printf("Enter uppercase character: ");
	scanf(" %c", &up_in);
	up_out = tolower(up_in);
	printf("Uppercase to lowercase: %c\n", up_out);

	return 0;
}