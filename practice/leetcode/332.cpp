#include <bits/stdc++.h>
using namespace std;

using vs = vector<string>;
using vss = vector<vs>;

vs findItinerary(vss& tickets) {
    map<string, vs> adj;
    for(auto t : tickets) adj[t[0]].push_back(t[1]);
    
    for(auto x : adj) sort(adj[x.first].begin(), adj[x.first].end(), greater<string>{});
    stack<string> st;
    vector<string> cir;

    string cur = "JFK";
    st.push(cur);

    while(!st.empty()) {
        if(adj[cur].size()) {
            st.push(cur);
            string nxt = adj[cur].back();
            adj[cur].pop_back();
            cur = nxt;
        } else {
            cir.push_back(cur);
            cur = st.top(), st.pop();
        }
    }
    reverse(cir.begin(), cir.end());
    return cir;
}

int main() {
    int n;
    cin >> n;
    vss v;
    while(n--) {
        string a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for(auto x : findItinerary(v))
        cout << x << ' ';
    cout << '\n';
}
