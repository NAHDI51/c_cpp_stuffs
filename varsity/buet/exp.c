#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

extern char *ones[] = {"zero", "one", "two",   "three", "four", "five", "six", "seven", "eight", "nine"};
extern char *tens[] = {"ten",   "twenty",  "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

#define MAX_LEN 2000
#define TRUE 1
#define FALSE 0

int isDig(char ch) {
  if (ch >= '0' && ch <= '9') return TRUE;
  return FALSE;
}

void con_chr(char* s, char c) {
  int l = strlen(s);
  *(s+l) = c;
  *(s+l+1) = '\0';
}

void con_str(char* s, char* t) {
  int slen = strlen(s);
  int i = 0;

  while(*(t+i) != '\0') {
    *(s+slen+i) = *(t+i);
    i++;
  }
  *(s+slen+i) = '\0';
}


char* num_to_word(int num) {
  char* str = (char*) malloc(15);
  *str = '\0';
  if(num < 10) con_str(str, ones[num]) ;
  if(10 <= num && num < 100) con_str(str, tens[num/10-1]);
  if(num > 100) {
    con_str(str, ones[num/100]);
    char* hund = " hundred";
    con_str(str, hund);
  }
  return str;
}

// Example usage
int main() {
    int num = 300;
    printf("%s\n", num_to_word(num));
}
