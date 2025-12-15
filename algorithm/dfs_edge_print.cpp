#include <bits/stdc++.h>
using namespace std;

#define BLACK 1
#define GRAY 2
#define WHITE 0

vector<vector<int>> adj;
vector<int> color;
vector<pair<int, int>> stamp;
int tim;

void print_edge(int c, int e, string edge) {
    cout << "{" << c << ", " << e << '}' << " - " << edge << '\n';
}

void dfs(int u) {
    tim++;
    color[u] = GRAY;
    stamp[u].first = tim;

    for(auto v : adj[u]) {
        if(color[v] == WHITE) 
            print_edge(u, v, "Tree Edge"), dfs(v);

        else if(color[v] == GRAY) 
            print_edge(u, v, "Back Edge");
        
        else {
            if(stamp[v].first < stamp[u].first) 
                print_edge(u, v, "Cross Edge");
            else
                print_edge(u, v, "Forward Edge");
        }
    }
    tim++;
    color[u] = BLACK;
    stamp[u].second = tim;
}

int main() {
    cout << "Enter the number of vertices: ";
    int n;
    cin >> n;
    adj.resize(n+1);
    color.resize(n+1);
    stamp.resize(n+1);

    cout << "Enter the edges (Enter (0, 0) to exit): \n";
    while(1) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) break;
        adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
     
    tim = 0;
    dfs(3);
    dfs(4);
}