#include <bits/stdc++.h>
using namespace std;

using vi=vector<int>;
using vii = vector<vi>;
#define mx 100001

void dfs(vii& adj, int u, vi& cir) {
    if(!adj[u].empty()) {
        auto v = adj[u].back();
        adj[u].pop_back();
        dfs(adj, v, cir);
    }
    cir.push_back(u);
}

vii validArrangement(vii& pairs) {
    vii adj(mx);
    vi indeg(mx), outdeg(mx);
    for(auto x : pairs) {
        int a = x[0], b = x[1];
        adj[a].push_back(b);
    }

    int start = 100002, end = mx+1;
    for(int i = 0; i < adj.size(); i++) {
        for(int j = 0; j < adj[i].size(); j++)
            outdeg[i]++, indeg[adj[i][j]]++;
    }
    for(int i = 1; i < mx; i++) {
        if(outdeg[i]>indeg[i]) start = i;
        else if(indeg[i]>outdeg[i]) end = i;
    }
    if(start == mx+1) start = 1;
    if(end != mx+1) adj[end].push_back(start);

    vi cir;
    dfs(adj, start, cir);
    reverse(cir.begin(), cir.end());
    vii ans;
    for(int i = 0; i < cir.size()-1; i++)
        ans.push_back({cir[i], cir[i+1]});
    
    if(end != mx+1) {
        for(auto i = ans.begin(); i != ans.end(); i++)
            if((*i)[0] == end && (*i)[1] == start) ans.erase(i);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vii v;
    while(n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    cout << '\n';
    for(auto x : validArrangement(v)) 
        cout << x[0] << ' ' << x[1] << '\n';
    cout << '\n';
}