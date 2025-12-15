#include <stdio.h>

int binarysearch(int l, int r, int arr[], int key) {
    // Element not found
    if(l > r) return -1;

    int mid = (l+r) / 2;

    // we found the element
    if(arr[mid] == key) return mid;

    // Element too small: search l, mid-1
    else if(key < arr[mid]) return binarysearch(l, mid-1, arr, key);
    
    // element too big: search mid+1, r
    else return binarysearch(mid+1, r, arr, key);
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,11};
    int size = 11;
    printf("Enter the element you want to search: ");

    int key;
    scanf("%d", &key);

    int index = binarysearch(0, size-1, arr, key);
    if(index == -1) {
        printf("Key %d not found!\n", key);
    } else {
        printf("The index of the key is: %d\n", index);
    }
    return 0;
}