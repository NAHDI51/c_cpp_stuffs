#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;

int l, n, m, dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
ll power = 1;
vector<vector<ll>> v;

void bfs(pair<int, int> start) {
    bool vis[n + 3][m + 3];
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, pair<int, int>>> pq;
    queue<pair<int, int>> q;
    q.push(start);
    while (not q.empty()) {
        int i = q.front().first, j = q.front().second;
        vis[i][j] = 1;
        power += max(0ll, v[i][j]);
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k], nj = j + dc[k];
            if (not vis[ni][nj] and v[ni][nj] != -9) {
                vis[ni][nj] = 1;
                if (v[ni][nj] == -1) q.push({ni, nj});
                else pq.push({-v[ni][nj], {ni, nj}});
            }
        }
        while (not pq.empty() and -pq.top().first <= power) {
            q.push({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> n >> m;
    v.resize(n + 3, vector<ll>(m + 3));
    pair<int, int> start = {1, 1};
    for (int i = 0; i < l; i++) {
        for (int j = 0; j <= n + 1; j++) {
            for (int k = 0; k <= m + 1; k++) {
                v[j][k] = -9;
            }
        }
        pair<int, int> new_start = {-1, -1};
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                cin >> v[j][k];
                if (v[j][k] == -1) new_start = {j, k};
            }
        }
        // do something
        bfs(start);
        start = new_start;
    }
    cout << power << endl;
    return 0;
}