#include <bits/stdc++.h>
using namespace std;

#define MAX 100000000
vector<int> bellman_ford(vector<array<int, 3>>& edges, int s, int ver) {
    vector<int> dist(ver);
    vector<int> parent(ver);
    for(auto x : dist) x = MAX;

    dist[s] = 0;
    for(int i = 1; i < ver; i++) {
        for(auto e : edges) {
            if(dist[e[1]] > (dist[e[0]] + e[2])) {
                dist[e[1]] = dist[e[0]] + e[2];
                parent[e[1]] = e[0];
            }
        }
    }
}

int main() {

}