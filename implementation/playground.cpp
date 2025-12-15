#include <bits/stdc++.h>
using namespace std;

#define MAX 100000000
#define INF MAX
using vi=vector<int>;
using vii = vector<vi>;
using st = string;
using vs = vector<st>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;

//casually write all the algorithms you want in this file.

/*
string manacher(string& s) {
    vector<int> odd(s.size(), 0);
    vector<int> even(s.size(), 0);

    for(int i = 0, l = 0, r = -1; i < s.size(); i++) {
        int k = (i > r) ? 1 : min(odd[r+l-i], r-i+1);
        while(0 <= i-k && i+k < s.size() && s[i-k] == s[i+k]) k++;
        odd[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }

    for(int i = 0, l = 0, r = -1; i < s.size(); i++) {
        int k = (i > r) ? 0 : min(even[r+l-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < s.size() && s[i-k-1] == s[i+k]) k++;
        even[i] = k--;
        if(i+k > r) r = i+k, l = i-k-1;
    }

    int mx = 0, mx_indx;
    for(int i = 0; i < s.size(); i++) {
        if(mx < odd[i]*2-1) 
            mx = odd[i]*2-1, mx_indx = i-odd[i]+1;
        if(mx < even[i]*2)
            mx = even[i]*2, mx_indx = i-even[i];
    }
    return s.substr(mx_indx, mx);
}
*/

string manacher(string& s) {
    int n = s.size();
    vector<int> even(n), odd(n);

    for(int i = 0, r = -1, l = 0; i < n; i++) {
        int k = (i > r) ? 1 : min(odd[r+l-i], r-i+1);
        while(0 <= i-k && i+k < n && s[i+k] == s[i-k]) k++;
        odd[i] = k--;
        if(i+k > r) r = i+k, l = i-k;
    }

    for(int i = 0, r = -1, l = 0; i < n; i++) {
        int k = (i > r) ? 0 : min(even[r+l-i+1], r-i+1);
        while(0 <= i-k-1 && i+k < n && s[i+k] == s[i-k]) k++;
        even[i] = i--;
        if(i+k > r) r = i+k, l = i-k-1;
    }

    int mx = 0, mx_indx;
    for(int i = 0; i < n; i++) {
        if(mx < odd[i]*2-1)
            mx = odd[i]*2-1, mx_indx = i-odd[i]+1;
        if(mx < even[i]*2)
            mx = even[i]*2, mx_indx = i-even[i];
    }
    return s.substr(mx_indx, mx);

}

string reverse_manacher(string& s) {
    int n = s.size();
    vector<int> odd(n), even(n);

    for(int i = n-1, l = n, r = n-1; i >= 0; i--) {
        int k = (i < l) ? 1 : min(odd[l+r-i], i-l+1);
        while(0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
        odd[i] = k--;
        if(i-k < l) l = i-k, r = i+k;
    }

    for(int i = n-1, l = n, r = n-1; i >= 0; i--) {
        int k = (i < l) ? 0 : min(even[l+r-i-1], i-l+1);
        while(0 <= i-k && i+k+1 < n && s[i-k] == s[i+k+1]) k++;
        even[i] = k--;
        if(i-k < l) l = i-k, r = i+k+1;
    }

    int mx = 0, mx_indx;
    for(int i = 0; i < n; i++) {
        if(mx < odd[i]*2-1)
            mx = odd[i]*2-1, mx_indx = i-odd[i]+1;
        if(mx < even[i]*2)
            mx = even[i]*2, mx_indx = i-even[i]+1;
    }
    return s.substr(mx_indx, mx);
}


int bfs(vector<vector<int>>& adj, int s, int t) {
    int n = adj.size();
    vector<bool> vis(n);
    vector<int> dist(n);
    queue<int> q;

    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!vis[v]) {
                vis[v] = true;
                q.push(v);
                dist[v] = dist[u]+1;
            }
        }
    }
    return dist[t];
}

int paths(vector<vector<int>>& adj, int s, int t) {
    int n = adj.size();
    vb vis(n, false);
    vi dist(n, MAX);
    vi path(n, 0);
    queue<int> q;

    dist[s] = 0;
    path[s] = 1;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!vis[v]) vis[v] = true, q.push(v);
            if(dist[v] > dist[u]+1) dist[v] = dist[u]+1, path[v] = path[u];
            else if(dist[v] == dist[u]+1) path[v] += path[u];
        }
    }
}

void __print_path(vi& path) {
    for(auto x : path)
        cout << x << '\t';
    cout << '\n';
}

void print_path(vi& path, vii& sol, int len, int u) {
    if(len == 1) {
        __print_path(path);
        return;
    }
    for(auto v : sol[u]) {
        path.push_back(v);
        print_path(path, sol, len-1, v);
        path.pop_back();
    }
}

pair<int, vii> all_paths(vector<vector<int>>& adj, int s, int t) {
    int n = adj.size();
    vb vis(n, false);
    vi dist(n, INF);
    vii sol(n);

    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(auto v : adj[u]) {
            if(!vis[v]) vis[u] = true, q.push(v);
            if(dist[v] > dist[u]+1) dist[v] = dist[u]+1,  sol[v] = {u};
            else if(dist[v] == dist[u]+1) sol[v].push_back(u);
        }
    }
    return {dist[t], sol};
}

vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int s) {
    vector<int> dist(adj.size(), INF);
    vector<bool> vis(adj.size(), false);
    vector<int> path(adj.size(), 0);
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    dist[s] = 0;
    pq.push({dist[s],s});

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto a : adj[u]) {
            int v = a.second, w = a.first;
            if(dist[v] > dist[u]+w) {
                dist[v] = dist[u]+w, pq.push({dist[v],v});
                //Extention: Count the number of shortest paths
                path[v] = path[u];
            } else if(dist[v] == dist[u]+w)
                path[v] += path[u];
        }
    }
}

void topological_sort(vii& adj, vb& vis, int u, vi& ans) {
    vis[u] = true;
    for(auto v : adj[u]) 
        if(!vis[v]) topological_sort(adj, vis, v, ans);
    ans.push_back(u);
}



int main() {

}