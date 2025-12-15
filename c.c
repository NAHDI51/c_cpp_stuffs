#include <stdio.h>
#include <stdlib.h> // For malloc 

int main() {
    int input[5]; // A,B,C,D,E
    for(int i = 0; i < 5; i++)
        scanf("%d", &input[i]);

    // MANUAL ALLOCATION => DIRECT FROM MEMORY
    // Generating a hashtable of size 105
    // preference => manual allocation, auto allocation bhallage na
    int* hash_table = (int *) malloc(105 * sizeof(int)); 

    int hash_table[105];
    for(int i = 0; i < 105; i++) hash_table[i] = 0;

    //Increment the occurances of the numbers. 
    // Hash table: Treat the numbers as index in the number line.
    for(int i = 0; i < 5; i++) 
        hash_table[input[i]]++;  

    int count = 0; //Number of distinct integers.
    
    //Count the hashtable for unique instances
    for(int i = 0; i < 105; i++)
        if(hash_table[i] != 0)
            count++;

    printf("%d\n", count);

    return 0;
}