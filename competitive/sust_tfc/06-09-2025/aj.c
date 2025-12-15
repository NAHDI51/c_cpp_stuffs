#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        scanf("%d", &n);
        // printf("N: %d\n", n);
        int arr[1000];
        int prev_arr[1000];
        for(int i = 0; i < 1000; i++) arr[i] = -1;
        
        arr[0] = 1;
        for(int i = 2; i <= n; i++) {
            // copy arr to prev_arr
            for(int i = 0; i < 1000; i++) {
                prev_arr[i] = arr[i];
                // arr[i] = -1;
            }
            int cur = 0;
            int j;
            for(j = 0; prev_arr[j] != -1; j++) {
                cur = prev_arr[j]*i + cur;
                arr[j] = cur%10;
                cur /= 10;
            }
            // printf("i cur: %d %d\n", i , cur);
            while(cur != 0) {
                arr[j++] = cur%10;
                cur /= 10;
            }
            
        }
        
        int ind = 999;
        while(arr[ind] == -1) ind--;
        for(int i = ind; i >= 0; i--) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

