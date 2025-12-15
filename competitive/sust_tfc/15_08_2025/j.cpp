#include <bits/stdc++.h>
using namespace std;

struct Fenwick2D {
    int n;
    vector<vector<int>> ys;           // y-values per node
    vector<vector<int>> tree;         // inner BITs stored directly

    Fenwick2D(int n) : n(n), ys(n+1) {}

    // Collect all y-values that could appear in each node
    void add_point(int x, int y) {
        for (int i = x; i <= n; i += i & -i)
            ys[i].push_back(y);
    }

    // Build the inner BITs after sorting & unique
    void build() {
        tree.resize(n+1);
        for (int i = 1; i <= n; i++) {
            sort(ys[i].begin(), ys[i].end());
            ys[i].erase(unique(ys[i].begin(), ys[i].end()), ys[i].end());
            tree[i].assign(ys[i].size() + 1, 0); // +1 for 1-based BIT
        }
    }

    // Get compressed index of y in this node (1-based)
    int get_index(int i, int y) {
        return int(lower_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin()) + 1;
    }

    // Update inner BIT directly
    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += i & -i) {
            int yi = get_index(i, y);
            for (int j = yi; j < tree[i].size(); j += j & -j) {
                tree[i][j] = max(tree[i][j], val);
            }
        }
    }

    // Query inner BIT directly
    int query(int x, int y) {
        int res = 0;
        for (int i = x; i > 0; i -= i & -i) {
            int yi = upper_bound(ys[i].begin(), ys[i].end(), y) - ys[i].begin();
            for (int j = yi; j > 0; j -= j & -j) {
                res = max(res, tree[i][j]);
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,int>> a(n+1);
    vector<int> xs, ys;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        xs.push_back(a[i].first);
        ys.push_back(a[i].second);
    }

    // coordinate compress
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    for (int i = 1; i <= n; i++) {
        a[i].first = int(lower_bound(xs.begin(), xs.end(), a[i].first) - xs.begin()) + 1;
        a[i].second = int(lower_bound(ys.begin(), ys.end(), a[i].second) - ys.begin()) + 1;
    }

    Fenwick2D bit((int)xs.size());

    // pre-add all points for offline building
    for (int i = 1; i <= n; i++) bit.add_point(a[i].first, a[i].second);
    bit.build();

    int ans = 0;
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        int best = bit.query(a[i].first - 1, a[i].second - 1);
        dp[i] = best + 1;
        bit.update(a[i].first, a[i].second, dp[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}