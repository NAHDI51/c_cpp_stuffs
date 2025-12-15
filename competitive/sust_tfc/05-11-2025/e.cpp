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
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <initializer_list>
#include <tuple>
using namespace std;

// Template
// ==============================================
    // pbds
    // #include <ext/pb_ds/assoc_container.hpp>
    // #include <ext/pb_ds/tree_policy.hpp>
    // using namespace __gnu_pbds;
    // template<typename T, typename comp = less<T>>
    // using ordered_set =  tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

    // Debugging
    #ifdef LOCAL
    #include "debug.h"
    #else
    #define debug(...)
    #define see(x)
    #endif

    typedef long long ll;
    typedef vector<int> VI;
    typedef vector<long long> VLL;
    typedef vector<bool> VB;
    typedef vector<vector<int>> VVI;
    typedef pair<int, int> PI;
    typedef pair<ll, ll> PLL;
    typedef vector<pair<int, int>> VPI;

    #define pb push_back
    #define ff first
    #define ss second
    #define mp make_pair
    #define all(a) a.begin(), a.end()
    #define revall(a) a.rbegin(), a.rend()

    #define loop(i, s, e) for (int i = s; i < e; ++i)
    #define inp(v) for (auto& x : v) cin >> x
    #define outp(v) for (int i = 0, n = v.size(); i < n; ++i) cout << v[i] << " \n"[i == n - 1]

    #define nl "\n"
    #define yep cout << "YES\n"
    #define nope cout << "NO\n"

    #define INF (int) 2e9
    #define INFL (ll) 1e18
    // #define MOD 998244353
    #define MOD 1000000007
    #define MAXN 200002
// ==============================================

int n, m;

vector<string> slant(vector<string> s, char dir)
{
    if (dir == 'U')
    {
        loop(i, 0, n)
        {
            loop(j, 0, m) if (s[i][j] == 'X')
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (s[k][j] != '.') break;

                    s[k][j] = 'X', s[k + 1][j] = '.';
                }
            }
        }
    }
    else if (dir == 'D')
    {
        for (int i = n - 1; i >= 0; --i)
        {
            loop(j, 0, m) if (s[i][j] == 'X')
            {
                for (int k = i + 1; k < n; ++k)
                {
                    if (s[k][j] != '.') break;

                    s[k][j] = 'X', s[k - 1][j] = '.';
                }
            }
        }
    }
    else if (dir == 'L')
    {
        for (int j = m - 1; j >= 0; --j)
        {
            loop(i, 0, n) if (s[i][j] == 'X')
            {
                for (int k = j - 1; k >= 0; --k)
                {
                    if (s[i][k] != '.') break;

                    s[i][k] = 'X', s[i][k + 1] = '.';
                }
            }
        }
    }
    else
    {
        loop(j, 0, m)
        {
            loop(i, 0, n) if (s[i][j] == 'X')
            {
                for (int k = j + 1; k < m; ++k)
                {
                    if (s[i][k] != '.') break;

                    s[i][k] = 'X', s[i][k - 1] = '.';
                }
            }
        }
    }

    return s;
}

void solve(int tc)
{
    cin >> n >> m;
    vector<string> s(n), final(n);

    loop(i, 0, n) cin >> s[i];
    loop(i, 0, n) cin >> final[i];

    map<vector<string>, bool> vis;
    vis[s] = true;

    vector<vector<string>> dp;
    dp.pb(s);

    vector<char> moves = {'U', 'D', 'L', 'R'};
    while (!dp.empty())
    {
        vector<string> now = dp.back();
        dp.pop_back();

        for (char c : moves)
        {
            vector<string> res = slant(now, c);

            if (res == final)
            {
                // debug(c);
                // loop(i, 0, n) debug(now[i]);
                yep;
                return;
            }

            if (!vis[res])
            {
                vis[res] = true;
                dp.pb(res);
            }
        }
    }

    nope;
}
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    int x = t;
    while(t--) solve(x - t);
    
    #ifdef LOCAL
    cerr << "Execution time: " << 1000.f * clock() / CLOCKS_PER_SEC << " ms." << nl;
    #endif
    
    return 0;
}