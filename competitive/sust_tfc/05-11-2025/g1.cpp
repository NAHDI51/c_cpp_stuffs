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
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<ll> d(n);
    for (int i = 0; i < n; ++i) cin >> d[i];

    vector<vector<ll>> t(3, vector<ll>(n));
    for (int p = 0; p < 3; ++p)
        for (int i = 0; i < n; ++i)
            cin >> t[p][i];

    // build arrivals for a person p: arr[s][i] = time when person p starting at s arrives at attraction i
    auto build_arrivals_for = [&](int p) {
        vector<ll> arr_from1(n, 0);
        for (int i = 1; i < n; ++i)
            arr_from1[i] = arr_from1[i-1] + t[p][i-1] + d[i-1];
        ll total = arr_from1[n-1] + t[p][n-1] + d[n-1];

        vector<vector<ll>> arr(n, vector<ll>(n));
        for (int s = 0; s < n; ++s) {
            ll base = arr_from1[s];
            for (int i = 0; i < n; ++i) {
                ll v = arr_from1[i] - base;
                if (v < 0) v += total;
                arr[s][i] = v;
            }
        }
        return make_pair(arr, total);
    };

    vector<vector<vector<ll>>> arrivals(3);
    vector<ll> totals(3);
    for (int p = 0; p < 3; ++p) {
        auto pr = build_arrivals_for(p);
        arrivals[p] = move(pr.first);
        totals[p] = pr.second;
    }

    auto overlap = [&](ll a, ll ta, ll b, ll tb) -> bool {
        // [a,a+ta) and [b,b+tb) overlap iff NOT (a+ta <= b || b+tb <= a)
        return !(a + ta <= b || b + tb <= a);
    };

    // build allowed[p][q][s_p] = bitset of s_q that do NOT conflict with p starting at s_p
    auto build_allowed = [&](int p, int q) {
        vector<bitset<400>> allowed(n);
        for (int sp = 0; sp < n; ++sp) {
            bitset<400> mask;
            for (int sq = 0; sq < n; ++sq) {
                if (sq == sp) continue; // must start at different attractions
                bool ok = true;
                for (int i = 0; i < n; ++i) {
                    if (overlap(arrivals[p][sp][i], t[p][i], arrivals[q][sq][i], t[q][i])) {
                        ok = false;
                        break;
                    }
                }
                if (ok) mask.set(sq);
            }
            allowed[sp] = mask;
        }
        return allowed;
    };

    auto allowed01 = build_allowed(0, 1);
    auto allowed02 = build_allowed(0, 2);
    auto allowed12 = build_allowed(1, 2);

    // search for s0,s1,s2 such that all pairwise allowed(s0,s1), allowed(s0,s2), allowed(s1,s2)
    for (int s0 = 0; s0 < n; ++s0) {
        auto mask01 = allowed01[s0];
        if (!mask01.any()) continue;
        // iterate s1 over set bits of mask01
        for (int s1 = 0; s1 < n; ++s1) {
            if (!mask01.test(s1)) continue;
            bitset<400> cand = allowed02[s0] & allowed12[s1];
            cand.reset(s0);
            cand.reset(s1);
            if (cand.any()) {
                int s2 = -1;
                for (int k = 0; k < n; ++k) if (cand.test(k)) { s2 = k; break; }
                cout << (s0 + 1) << " " << (s1 + 1) << " " << (s2 + 1) << "\n";
                return 0;
            }
        }
    }

    cout << "impossible\n";
    return 0;
}
