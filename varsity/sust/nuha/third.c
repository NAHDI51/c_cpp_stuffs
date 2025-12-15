#include <stdio.h>
#include <string.h>
#include <ctype.h>

void count(char* s, int* vcnt, int* ccnt) {
    int k = strlen(s);
    for(int i = 0; i < k; i++) {
        char c = tolower(s[i]);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            (*vcnt)++;
        else (*ccnt)++;
    }
}

int main() {
    char s[100];
    scanf("%s", s);
    int vcnt = 0, ccnt = 0;
    count(s, &vcnt, &ccnt);
    printf("%d vowels and %d consonants", vcnt, ccnt);
}