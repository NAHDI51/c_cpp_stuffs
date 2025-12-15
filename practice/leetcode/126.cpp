#include <bits/stdc++.h>
using namespace std;

using st=string;
using vs= vector<st>;
using vss = vector<vs>;
using vb = vector<bool>;
using vi = vector<int>;
using vii = vector<vi>;
#define INF 100000000

pair<vii, int> bfs(vii& adj, int s, int t) {
    vb vis(adj.size());
    vi dist(adj.size(), INF);
    vii sol(adj.size());

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!vis[v]) vis[v] = true, q.push(v);
            if(dist[v] > dist[u]+1) {
                dist[v] = dist[u]+1;
                sol[v] = {u};
            } else if(dist[v] == dist[u]+1)
                sol[v].push_back(u);
        }
    }
    return {sol, dist[t]};
}

void backtrack(vii& adj, vs& vert, int u, int lvl, st& src, vss& paths, vs& path) {
    if(lvl == 0) {
        path.push_back(src);
        paths.push_back(path);
        path.pop_back();
        return;
    }
    for(auto v : adj[u]) {
        path.push_back(vert[v]);
        backtrack(adj, vert, v, lvl-1, src, paths, path);
        path.pop_back();
    }
}

vss findLadders(st bw, st ew, vs& vert) {
    int n = vert.size();
    int s = n, t = n+1;
    for(int i = 0; i < vert.size(); i++) {
        if(vert[i] == bw) s = i;
        if(vert[i] == ew) t = i; 
    }
    if(t == n+1) return vss{};
    if(s == n) vert.push_back(bw);

    vii adj(vert.size());
    for(int i = 0; i < vert.size()-1; i++) {
        for(int j = i+1; j < vert.size(); j++) {
            int dif = 0;
            for(int k = 0; k < vert[0].size(); k++) 
                if(vert[i][k] != vert[j][k]) dif++;
            
            if(dif == 1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    auto x = bfs(adj, s, t);
    auto sol = x.first;
    auto shortestPath = x.second;
    if(shortestPath == INF) return vss{};

    vss paths;
    vs path;
    
    path.push_back(vert[t]);
    backtrack(sol, vert, t, shortestPath-1, bw, paths, path);
    for(int i = 0; i < paths.size(); i++)
        reverse(paths[i].begin(), paths[i].end());
    
    return paths;
}

int main() {
    st beg, end;
    cin >> beg >> end;
    int n;
    cin >> n;
    vs words;
    while(n--) {
        st s;
        cin >> s;
        words.push_back(s);
    }
    for(auto x : findLadders(beg, end, words)) {
        for(auto y : x)
            cout << y << ' ';
        cout << '\n';
    }
}