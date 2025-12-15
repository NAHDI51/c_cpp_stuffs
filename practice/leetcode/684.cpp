#include <bits/stdc++.h>
using namespace std;

//Krushal's Algorithm
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int mx = 0;
    for(auto e : edges) mx = max(mx, max(e[0], e[1]));

    vector<int> size(mx);
    vector<int> ancestor(mx);

    for(int i = 0; i < mx; i++) size[i] = 1, ancestor[i] = i;

    auto find = [&] (int a) -> int {
        while(ancestor[a] != a) a = ancestor[a];
        return a;
    };
    auto same = [&] (int a, int b) -> bool {
        return find(a) == find(b);
    };
    auto join = [&] (int a, int b) -> void {
        a = find(a), b = find(b);
        if(size[a] < size[b]) swap(a, b);
        size[a] += size[b];
        ancestor[b] = a;
    };

    for(auto e : edges) {
        if(!same(e[0], e[1])) join(e[0], e[1]);
        else return {e[0], e[1]};
    }
    return {0, 0};
}

int main() {
    vector<vector<int>> edges;
    int n;
    cin >> n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }
    cout << findRedundantConnection(edges)[0] << findRedundantConnection(edges)[1] << '\n';
}