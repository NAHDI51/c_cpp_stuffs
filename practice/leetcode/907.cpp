#include <bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& a) {
    vector<int> dp(a.size());
    stack<int> st;
    int mod = (int) 1e9+7;
    //we are going to store stack's index.
    for(int i = 0; i < a.size(); i++) {
        while(!st.empty() && a[i] < a[st.top()]) st.pop();
        if(st.empty()) dp[i] = a[i] * (i+1);
        else dp[i] = (a[i] * (i - st.top())) + dp[st.top()];
        st.push(i);
    }
    int cnt = 0;
    for(auto x : dp) cnt += x, cnt %= mod;
    return cnt;
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
    cout << sumSubarrayMins(a) << '\n';
}