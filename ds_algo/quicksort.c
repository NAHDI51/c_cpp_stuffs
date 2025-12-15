#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r) {
    // assume pivot = a[r]
    int pivot = a[r];
    int lo = l;

    for(int j = l; j <= r; j++) {
        if(a[j] < pivot) {
            swap(a+lo++, a+j);
        }
    }
    swap(a+lo, a+r);
    return lo;
}

void quickSort(int a[], int l, int r) {
    if(l < r) {
        int pivot = partition(a, l, r);
        quickSort(a, l, pivot-1), quickSort(a, pivot+1, r);
    }
}

int main() {
    int a[] = {1,73,4,7,7,3,63,84,53,23,5};
    quickSort(a, 0, 10);
    for(int i = 0; i < 11; i++) printf("%d ", a[i]);
}