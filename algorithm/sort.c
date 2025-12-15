#include <stdio.h>
#include <stdlib.h>

#define OFFLINE

#ifdef ONLINE
#undef OFFLINE
#endif

#ifdef OFFLINE
#undef ONLINE
#endif

int main() {

	#ifndef OFFLINE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
	#endif

	int *a;
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);
	a = malloc(size*4);

	if(a == NULL) {
		fprintf(stderr, "Erorr occured: Bad allocation.\n");
		exit(1);
	}

	for(int i = 0; i < size; i++) {
		printf("Enter element #%d: ", i);
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < size-1; i++) 
		for(int j = i+1; j < size; j++) 
			if(a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}

	printf("Sorted array: ");
	for(int i = 0; i < size; i++) printf("%d ", a[i]);
	printf("\n");
}