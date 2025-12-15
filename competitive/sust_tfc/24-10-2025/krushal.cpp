#include <bits/stdc++.h>
using namespace std;

class comp {
public:
    bool operator()(array<int, 3>& a, array<int, 3>& b) {
        return a[2] < b[2];
    }
};

vector<array<int, 3>> krushal(vector<array<int, 3>>& edges, int sz) {
    vector<int> ancestor(sz+1);
    vector<int> size(sz+1);

    for(int i = 0; i < ancestor.size(); i++) ancestor[i] = i, size[i] = 0;

    auto find = [&](int a) -> int {
        while(ancestor[a] != a) a = ancestor[a];
        return a;
    };
    auto same = [&](int a, int b) -> bool {
        return find(a) == find(b);
    };
    auto join = [&](int a, int b) -> void {
        a = find(a), b = find(b);
        if(size[a] < size[b]) swap(a, b);
        ancestor[b] = a, size[a] += size[b];
    };

    sort(edges.begin(), edges.end(), comp{});
    for(auto x : edges) cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
    cout << '\n';

    vector<array<int, 3>> ans;
    for(auto e : edges) {
        if(!same(e[0], e[1])) join(e[0], e[1]), ans.push_back(e);
    }
    return ans;
}

int main() {
    vector<array<int, 3>> edges;
    cout << "Please enter your edges: (Enter 0 0 0 to exit)\n";
    int mx = 0;
    while(1) {
        int a, b, c;
        cin >> a >> b >> c;
        mx = max({mx, a, b});
        if(a == 0 && b == 0 && c == 0)
            break;
        edges.push_back({a, b, c});
    }
    cout << '\n';
    for(auto x : krushal(edges, mx))
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
}