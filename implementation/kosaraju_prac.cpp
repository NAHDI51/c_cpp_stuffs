#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

int tim = 0;
vector<int> stamp;

void dfs1(vector<vector<int>>& adj, vector<bool>& visited, int v) {
    visited[v] = true;
    for(auto u : adj[v])
        if(!visited[u]) dfs1(adj, visited, u);
    tim++;
    stamp[tim] = v; // finishing order
}

void dfs2(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& components, int v) {
    visited[v] = true;
    components.push_back(v);
    for(auto u : adj[v])
        if(!visited[u]) dfs2(adj, visited, components, u);
}

vector<vector<int>> kosaraju(vector<vector<int>>& adj) {
    int n = adj.size() - 1; // since adj is 1-based
    tim = 0;
    stamp.assign(n + 5, 0);
    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj2(n + 1);

    // reverse graph
    for(int i = 1; i <= n; i++) {
        for(int j : adj[i])
            adj2[j].push_back(i);
    }

    // first dfs (original graph)
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) dfs1(adj, visited, i);
    }

    fill(visited.begin(), visited.end(), false);

    vector<vector<int>> scc;
    for(int i = tim; i >= 1; i--) {
        int v = stamp[i];
        if(!visited[v]) {
            vector<int> comp;
            dfs2(adj2, visited, comp, v);
            scc.push_back(comp);
        }
    }
    return scc;
}

int main() {
    vector<vector<int>> adj;

    int n;
    cout << "enter the number of vertices in the graph: ";
    cin >> n;
    adj.resize(n+1);

    cout << "enter the edges (Enter zz to exit): '\n";
    while(1) {
        string s;
        cin >> s;
        if(s == "zz") break;

        adj[(int)(s[0]-112)].push_back((int)(s[1]-112));
    }
    for(int i = 1; i < adj.size(); i++) sort(adj[i].begin(), adj[i].end());

    tim = 0;
    auto ans = kosaraju(adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << i+1 << '\t';
        for(int j = 0; j < ans[i].size(); j++)
            cout << (char) (ans[i][j]+112) << ' ';
        cout << '\n';
    }
    return 0;
}