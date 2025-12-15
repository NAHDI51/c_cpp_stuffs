#include <bits/stdc++.h>
using namespace std;


//INVARIANTS
/*
1. We add positive numbers, regardless of things.
2. If total sum is negative, and our candidate is positive, then we discard the whole stack.
3. WHAT TO DO WITH NEGATIVE NUMBERS?
//Maybe a priority queue?
*/

//PRIORITY_QUEUE [O(NlogN)]
int dp[100001];
/*
class comp {
public:
bool operator()(int& a, int& b) {
    return dp[a] < dp[b];
}
};

int constrainedSubsetSum(vector<int>& a, int k) {
    priority_queue<int, vector<int>, comp> pq;
    dp[0] = a[0], pq.push(0);

    int mx = a[0];
    for(int i = 1; i < a.size(); i++) {
        dp[i] = dp[pq.top()] + a[i];
        mx = max(dp[i], mx);
        while(pq.top() <= i-k) pq.pop();
        pq.push(i);
    }
    return mx;
}
*/

//MONOTONIC QUEUE O(N)
int constrainedSubsetSum(vector<int>& a, int k) {
    deque<int> dq;
    dp[0] = a[0], dq.push_back(0);
    int mx = a[0];
    for(int i = 1; i < a.size(); i++) {
        dp[i] = max(dp[dq.front()] + a[i], dp[i]);
        mx = max(mx, dp[i]);
        while(!dq.empty() && dp[dq.back()] < dp[i]) dq.pop_back();
        while(!dq.empty() && dq.front() < (i-k+1)) dq.pop_front();
        dq.push_back(i);
    }
    return mx;
}

int main() {
    vector<int> a;
    int n, k;
    cin >> n >> k;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << constrainedSubsetSum(a, k) << '\n';
}