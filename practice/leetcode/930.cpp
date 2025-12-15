#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& a, int t) {
    int ans = 0;
    deque<int> dq;

    for(int i = 0, j = 0; i < a.size(); i++) {
        if(a[i] == 1) dq.push_back(i);
        if(dq.size() > t) j = dq.front() + 1, dq.pop_front();
        if(dq.size() == t) {
            if(dq.empty()) ans += (i-j+1);
            else ans += (dq.front()-j+1);
        }
    }
    return ans;
}

int main() {
    vector<int> a;
    int t, n;
    cin >> n >> t;
    while(n--) {
        int m;
        cin >> m;
        a.push_back(m);
    }
    cout << numSubarraysWithSum(a, t) << '\n';
}