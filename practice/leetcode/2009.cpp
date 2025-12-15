#include <bits/stdc++.h>
using namespace std;

//SPACE NOT OPTIMIZED O(N)
/*
int minOperations(vector<int>& a) {
    bitset<1000000> bt;
    int mx = 0;
    for(auto x : a) mx = max(mx, x);
    for(int i = 0; i < a.size(); i++) bt[a[i]] = true;
    int itm = 0;
    for(int i = 1; i < a.size(); i++) itm += (int) bt[i];

    int hi = itm;
    for(int j = 1, i = a.size(); i <= mx; i++, j++) {
        hi = max(hi, itm);
        itm -= (int) bt[j], itm += (int) bt[i];
    }
    return a.size() - hi;
}
*/

//space optimized O(N)
//The idea is to sort the array , and then maintain a sliding window 
int minOperations(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> a;
    for(int i = 0; i < n-1; i++) {
        while(arr[i] == arr[i+1]) i++;
        a.push_back(arr[i]);
    }
    if(arr.back() != a.back()) a.push_back(arr.back());
    
    int mx = 0;
    for(int i = 0, j = 0; i < a.size(); i++) {
        while(j <= i && (a[i]-a[j]+1) > n) j++;
        mx = max(mx, i-j+1);
    }
    return n - mx;
}


int main() {
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << minOperations(a) << '\n';
}