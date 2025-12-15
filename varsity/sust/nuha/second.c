#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    /**
     * arr[l..m] and arr[m+1..r] are the two partitions
     * temp is the temporary merged array 
     * After merging, temp is stored to arr. 
     */
    int temp[r-l+1];
    int i = l, j = m + 1, k = l;
    /**
     * i -> index of arr[l..m]
     * j -> index of arr[m+1..r]
     * k -> index of temp
     * We compare between two partitions. Whichever has lesser
     * value will be stored to temp. We check this, until one 
     * of the array runs out of its size (the while loop condition)
     */
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    /**
     * As Another one of the partition runs out of its size 
     * we may still have another partition active, and fill out
     * that partition now.
     */
    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    // Finally, store the merged array to main array.
    for (i = l; i <= r; i++) arr[i] = temp[i];
}
/*
2 5 4 3 3 7 1 5

// Bubble sort
// Binary search
// Merge sort 

l -> begin
r -> end

*/

void mergeSort(int arr[], int l, int r) {
    // If l == r, then we have only one element, and one element
    // is always sorted.
    if (l < r) {
        int m = l + (r - l) / 2;
        // Array will first sort the first half 
        mergeSort(arr, l, m);
        // Then the second half
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
