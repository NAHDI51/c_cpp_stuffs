#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;


//Most possibly Dijkstra's algorithm
void bfs(int c)
{
    deque<int> q;
    visited[c] = true, dist[c] = 0;
    q.push_back(c);
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (auto e : adj[v])
        {
            if (!visited[e])
            {
                visited[e] = true;
                dist[e] = dist[v] + 1;
                q.push_back(e);
            }
        }
    }
}

int main()
{
    cout << "Enter the number of vertices: ";
    int n;
    cin >> n;

    adj.resize(n + 1);
    visited.resize(n + 1);
    dist.resize(n + 1);
    cout << "Enter the edges (enter (0, 0) to end this): \n";
    while (1)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < adj.size(); i++)
        sort(adj[i].begin(), adj[i].end());
    cout << "Enter the vertex to search from: ";
    int c;
    cin >> c;
    bfs(c);
    for (int i = 1; i <= 8; i++)
        cout << dist[i] << '\n';
    cout << '\n';
}