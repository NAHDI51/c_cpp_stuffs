#include <stdio.h>
#include <stdlib.h>

int* countingSort(int a[], int n) {
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > mx) mx = a[i];
    }
    int* occ = (int*) malloc(4*(mx+1));
    for(int i = 0; i < n; i++) {
        occ[a[i]]++;
    }
    for(int i = 1; i <= mx; i++) {
        occ[i] += occ[i-1];
    }
    int* ans = malloc(4*n);
    for(int i = n-1; i >= 0; i--) {
        ans[occ[a[i]]-1] = a[i];
        occ[a[i]]--;
    }
    return ans;
}

int main() {
    int a[] = {1,73,4,7,7,3,63,84,53,23,5};
    int* ans = countingSort(a, 11);
    for(int i = 0; i < 11; i++) {
        printf("%d ", ans[i]);
    }
    return 0;
}