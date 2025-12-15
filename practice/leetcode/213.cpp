#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& a) {
    if(a.size() == 1) return a[0];
    if(a.size() == 2) return max(a[0], a[1]);

    int dp[101], dp2[101];
    dp[0] = a[0], dp[1] = a[1];
    priority_queue<int> pq;
    pq.push(dp[0]);

    for(int i = 2; i < a.size()-1; i++) {
        dp[i] = pq.top() + a[i];
        pq.push(dp[i-1]);
    }

    dp2[1] = a[1], dp2[2] = a[2];
    pq = priority_queue<int>();
    pq.push(dp2[1]);
    for(int i = 3; i < a.size(); i++) {
        dp2[i] = pq.top()+a[i];
        pq.push(dp2[i-1]);
    }
    return max(dp[a.size()-2], dp2[a.size()-1]);
    
}

int main( ){
    vector<int> a;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << rob(a) << '\n';
}