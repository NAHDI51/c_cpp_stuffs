#include <bits/stdc++.h>
using namespace std;

//Assumes the number of elements is at most maxN
#define maxN 100001

//count_sequences: counts the number of such
//sequences of length k.

//@param: 
//arr = the sequence to be counted.
//k = the number of elements each subset will contain.
//Returns: number of such elements
long long count_sequences(vector<int>& arr, int k) {
    //len[i] denotes the number of sequences with EXACTLY i length
    long long len[maxN+1]; 
    memset(len, 0, 8*k);

    //We always have an empty set
    len[0] = 1;
    for(int i = 0; i < arr.size(); i++) {
        //On each iteration, simply insert the
        //current element we are considering.
        //Insertion is just taking the one less length
        //and multiplying it with the number of 
        //variations we can insert.
        //len[j-1] is the one less length.
        for(int j = k; j >= 1; j--) 
            len[j] += len[j-1] * arr[i];
    }
    return len[k];
}

//Driver
int main() {
    //A, B, C, D, E
    vector<int> arr = {1,2,1,1,3};

    //Ouptut: 34
    cout << count_sequences(arr, 3) << '\n';
}