#include <bits/stdc++.h>
using namespace std;

//TESTCASE
/*
caotmcaataijjxi
oatjiioicitatajtijciocjcaaxaaatmctxamacaamjjx
*/

//Floyd Warshap All-pair shortest + accumulation
//WA
/*
#define MAX 100000000
int findRotateSteps(string ring, string key) {
    int dist[101][101];

    //Create the adjacency matrix of a cycle
    for(int i = 0; i < ring.size(); i++) {
        for(int j = 0; j < ring.size(); j++) {
            if(abs(i-j) == 1) dist[i][j] = 1, dist[j][i] = 1;
            else if(i == j) dist[i][j] = 0;
            else dist[i][j] = MAX, dist[j][i] = MAX;
        }
    }
    dist[0][ring.size()-1] = dist[ring.size()-1][0] = 1;
    //Floyd-Warshal Algorithm
    for(int k = 0; k < ring.size(); k++) {
        for(int i = 0; i < ring.size(); i++) {
            for(int j = 0; j < ring.size(); j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    //Display matrix

    for(int i = 0; i < ring.size(); i++) {
        for(int j = 0; j < ring.size(); j++)
            cout << dist[i][j] << '\t';
        cout << '\n';
    }

    vector<vector<int>> hash(26);
    for(int i = 0 ; i < ring.size(); i++)
        hash[ring[i]-97].push_back(i);

    int first = 0;
    int ans = 0;
    for(int i = 0; i < key.size(); i++) {
        int sec;
        int len = MAX;
        for(auto x : hash[key[i]-97]) {
            if(len > dist[first][x]) {
                len = dist[first][x];
                sec = x;
            }
        }
        first = sec;
        ans += len;
        ans++;
        //cout << len << '\n';
    }
    return ans;
}
*/

//BFS SIMULATION
//WA
/*
int findRotateSteps(string r, string k) {
    int n = r.size();
    vector<vector<int>> adj(n);
    for(int i = 1; i < n-1; i++) {
        adj[i].push_back(i-1);
        adj[i].push_back(i+1);
    }
    adj[0].push_back(1), adj[0].push_back(n-1);
    adj[n-1].push_back(0), adj[n-1].push_back(n-2);

    vector<char> hash(n);
    for(int i = 0 ; i < r.size(); i++) hash[i] = r[i];

    //returns distance and index number
    auto bfs = [&adj, &hash, &n] (int s, char t) -> pair<int, int> {
        vector<bool> visited(n);
        vector<int> dist(n);

        dist[s] = 0;
        visited[s] = true;
        queue<int> q;
        q.push(s);

        while(!q.empty()) {
            auto u = q.front();
            q.pop();
            if(hash[u] == t) return {dist[u], u};

            for(auto v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
        }
        return {-1, -1};
    };

    int t = 0;
    int first = 0;
    for(int i = 0; i < k.size(); i++) {
        auto temp = bfs(first, k[i]);
        t += temp.first, t++;
        first = temp.second;
    }
    return t;
}
*/



#define MAX 100000000
//Floyd Warshal + DYNAMIC PROGRAMMING
//Let dp[i][j] be the minimum steps taken to dial the first i keys, that stops at j.
//Then dp[i][j] = dp[i-1][k] + bfs(k,j), if dp[i-1][k] is not max, and hash[j] = key[i];
int findRotateSteps(string r, string k) {
    int n = r.size();
    //Adjacency Matrix
    int dist[101][101];

    //Create the adjacency matrix of a cycle
    for(int i = 0; i < r.size()-1; i++) {
        for(int j = i+1; j < r.size(); j++) {
            if(abs(i-j) == 1) dist[i][j] = 1, dist[j][i] = 1;
            else if(i == j) dist[i][j] = 0;
            else dist[i][j] = MAX, dist[j][i] = MAX;
        }
    }
    dist[0][r.size()-1] = dist[r.size()-1][0] = 1;
    //Floyd-Warshal Algorithm
    for(int k = 0; k < r.size(); k++) {
        for(int i = 0; i < r.size(); i++) {
            for(int j = 0; j < r.size(); j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    vector<char> hash(n);
    for(int i = 0; i < r.size(); i++) hash[i] = r[i];

    int dp[101][101];

    for(int i = 0; i <= k.size(); i++) {
        for(int j = 0; j < r.size(); j++)
            dp[i][j] = MAX;
    }
    dp[0][0] = 0;
    for(int i = 1; i <= k.size(); i++) {
        for(int j = 0; j < r.size(); j++) {
            if(hash[j] != k[i-1]) continue;

            for(int l = 0; l < r.size(); l++) {
                //Previous stop
                dp[i][j] = min(dp[i][j], dp[i-1][l] + dist[l][j]);
            }
            dp[i][j]++;
        }
    }
    int mn = MAX;
    for(int i = 0 ; i < r.size(); i++) mn = min(mn, dp[k.size()][i]);
    return mn;
}

//FINALLY GG
//THAT WAS ONE TOUGH SON OF A BITCH

int main() {
    string ring;
    string key;

    cin >> ring >> key;
    cout << findRotateSteps(ring, key) << '\n';
}