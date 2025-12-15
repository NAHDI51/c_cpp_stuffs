#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF 512

int main() {
    FILE* f = fopen("/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/stdio.h", "r");
    FILE* fw = fopen("stdio2.h", "w+");

    if(f == NULL) {
        fprintf(stdout, "Unable to open the file.\n");
        exit(1);
    }

    int count = 1;
    while(!feof(f)) {
        char b[BUF];
        int count = fread(b, 1, BUF, f);

        for(int i = 0; i < count; i++) {
            fprintf(fw, "%c", b[i]);
        }
    }

    fclose(f);
}