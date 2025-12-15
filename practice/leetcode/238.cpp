#include <bits/stdc++.h>
using namespace std;

vector<int> productExceptSelf(vector<int>& a) {
    int n = a.size();
    vector<int> prefix(n);
    vector<int> suffix(n);
    vector<int> ans(n);

    prefix[0] = 1;
    for(int i = 1; i < n; i++) 
        prefix[i] *= prefix[i-1];

    suffix[n-1] = 1;
    for(int i = n-2; n >= 0; i--)
        suffix[i] *= suffix[i+1];
    
    //Corner values
    ans[0] = suffix[1], ans[n-1] = prefix[n-2];

    for(int i = 1; i < n-1; i++)
        ans[i] = prefix[i-1] * suffix[i+1];
    
    return ans;
}

int main() {

}