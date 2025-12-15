#include <bits/stdc++.h>
using namespace std;

//The problem asks a variant: In how many ways can we make how many sum? 
int f(vector<int>& v) {
    int sm = 0;
    for(auto x : v) sm += x;
    vector<int> dp(sm+1);

    dp[0] = 1;
    for(int i = 0; i < v.size(); i++) 
        for(int j = sm; j >= 0; j--) 
            if(dp[j]) dp[j+v[i]] += dp[j];
    
    int mx = 0;
    int i = 0;
    //for(auto x : dp) cout << i++ << "  " << x << '\n';
    for(auto x : dp) mx += x; 
    return mx;
}

int main() {
    vector<int> v;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >>m;
        v.push_back(m);
    }
    cout << f(v) << '\n';
}