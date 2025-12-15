#include <bits/stdc++.h>
using namespace std;

using vi=vector<int>;
using vii = vector<vi>;

vi getOrder(vii& a) {
    map<vi, int> hash;
    for(int i = 0; i < a.size(); i++) hash[a[i]] = i;

    sort(a.begin(), a.end());

    priority_queue<vi, vii, greater<vi>> pq;

    int i = 0;
    int tim = 0;
    vi ans;
    while(!pq.empty() || i != a.size()) {
        if(pq.empty() && i != a.size())
            pq.push({a[i][1], hash[a[i]], a[i++][0]});
        
        auto s = pq.top();
        pq.pop();
        ans.push_back(hash[{s[2], s[0]}]);

        tim = s[2] + s[0];
        while(i != a.size() && a[i][0] <= tim) pq.push({a[i][1], hash[a[i]], a[i++][0]});
    }
    return ans;
}

int main() {
    vii a;
    int n;
    cin >> n;
    while(n--) {
        int p,q;
        cin >> p >> q;
        a.push_back({p, q});
    }
    for(auto x : getOrder(a))
        cout << x << ' ';
    cout << '\n';
}