#include <bits/stdc++.h>
using namespace std;

//MASSIVE BRUTE FORCE (TLE) : O(2^N*2)
/*
int sm = 0;
int sz = 0;
int mn = INT_MAX;
void back(vector<int>& a, int i, int s, int Sm) {
    if(s == sz) {
        mn = min(mn, abs(sm-Sm));
        return;
    }
    if(i == sz*2) return;
    back(a, i+1, s+1, Sm+a[i]);
    back(a, i+1, s, Sm);
}

int minimumDifference(vector<int>& a) {
    for(auto x : a) sm += x;
    sm /= 2;
    sz = a.size()/2;
    back(a, 0, 0, 0);
    return mn*2;
}
*/

//AC (O(N * 2^N))
#define MAX 1000000000
#define MIN -MAX
//Meet in the middle
int minimumDifference(vector<int>& a) {
    int sm = 0;
    for(auto x : a) sm += x;
    int off;
    (sm % 2) ? off = 1 : off = 0;
    sm /= 2;
    
    vector<int> p, q;
    for(int i = 0; i < a.size()/2; i++) p.push_back(a[i]);
    for(int i = a.size()/2; i < a.size(); i++) q.push_back(a[i]);

    int dp[1<<16];
    memset(dp, 0, sizeof(dp));
    
    for(int i = 1; i < 1<<p.size(); i++) {
        for(int j = 0; j < p.size(); j++) {
            if(i&(1<<j)) dp[i] += p[j];
        }
    }

    vector<set<int>> st(16);
    for(int i = 0; i < 16; i++) st[i].insert(MIN), st[i].insert(MAX);

    for(unsigned int i = 0; i < 1<<q.size(); i++) {
        int tot = 0;
        for(int j = 0; j < q.size(); j++) 
            if(i&(1<<j)) tot += q[j];
        st[__builtin_popcount(i)].insert(tot);
    }

    int mn = INT_MAX;
    for(unsigned int i = 0; i < 1<<p.size(); i++) {
        auto it = st[q.size()-__builtin_popcount(i)].upper_bound(sm - dp[i]);
        int cand1 = *it;
        --it;
        int cand2 = *it;
        mn = min({mn, abs(sm-(dp[i]+cand1)), abs(sm-(dp[i]+cand2))});
    }
    return (2*mn)+off;
}


int main() {
    vector<int> v;
    int n;
    cin >> n;
    while(n--) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    cout << minimumDifference(v) << '\n';
}