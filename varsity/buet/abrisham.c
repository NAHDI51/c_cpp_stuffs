#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern char *ones[] = {"zero", "one", "two",   "three", "four", "five", "six", "seven", "eight", "nine"};
extern char *tens[] = {"ten",   "twenty",  "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

#define MAX_LEN 2000
#define TRUE 1
#define FALSE 0
#define FLAG printf("reached here.\n");

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

char* substr (char* s, int i, int j) {
  char* str = (char*) malloc (j-i+2);
  int ind = 0;
  for(int k = i; k <= j; k++) *(str+ind++) = *(s+k);
  *(str+ind) = '\0';
  return str; 
}

int stoi(char* str) {
  while(*str == '0') str++;

  int ret = 0;
  while(*str != '\0' && isDig(*str)) {
    ret = ret * 10 + (*str-48);
    str++;
  }

  return ret; 
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

int main() {
  char *in  = (char *)malloc(MAX_LEN);
  char *out = (char *)malloc(MAX_LEN);

  // fgets(in, MAX_LEN, stdin);
  // scanf(" %[^\n]", in);
  int len = strlen(in);

  for (int i = 0; i < len; i++) {
    // FLAG;
    int j = i;
    while (isDig(*(in+j))) j++;
    j--;
    
    if(isDig(*(in+i))) {
      char* num = substr(in, i, j);
      int n = stoi(num);
      char* cand = num_to_word(n);
      con_str(out, cand);
      i = j; 
    } else {
      con_chr(out, *(in+i));
    }
  }
  printf("%s\n", out);
}