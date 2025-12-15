#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& a) {
    sort(a.begin(), a.end());
    int dp[1001];
    int sol[1001];
    dp[0] = 1;
    sol[0] = -1;
    int mx = 1, mx_indx = 0;
    for(int i = 1; i < a.size(); i++) {
        dp[i] = 1;
        sol[i] = -1;
        for(int j = 0; j < i; j++) {
            if((a[i] % a[j]) == 0) {
                if(dp[i] < dp[j]+1) {
                    dp[i] = dp[j]+1; 
                    sol[i] = j;
                }
            }
        }
        if(mx < dp[i]) {
            mx = dp[i]; 
            mx_indx = i;
        }
    }
    vector<int> ans;
    while(mx_indx != -1) 
        ans.push_back(a[mx_indx]), mx_indx = sol[mx_indx];
    return ans;
}

int main(){
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    for(auto x : largestDivisibleSubset(a))
        cout << x << '\t';
    cout << '\n';
}