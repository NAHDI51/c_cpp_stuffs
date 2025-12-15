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

const int MOD = 1000000007;
int m;
vector<int> dig;

// pack/unpack state into 1 int
inline int pack(int mnum, int S, int Q) {
    return (mnum * m + S) * m + Q;
}
inline tuple<int,int,int> unpack(int key) {
    int Q = key % m; key /= m;
    int S = key % m; key /= m;
    int mnum = key;
    return {mnum, S, Q};
}

// go(pos, mnum, S, Q, tight)
long long go(int pos, int mnum, int S, int Q, bool tight) {
    if (pos == (int)dig.size()) {
        int rhs;
        if (m % 2 == 1) {
            int inv2 = (m + 1) / 2; // inverse of 2 mod m
            rhs = ((S * S - Q + m) % m) * inv2 % m;
        } else {
            int val = (S * S - Q);
            val /= 2; // always integer
            rhs = ((val % m) + m) % m;
        }
        return (mnum == rhs);
    }

    if (!tight) {
        // iterative DP for the suffix
        unordered_map<int,long long> cur, nxt;
        cur.reserve(1<<12);
        cur.max_load_factor(0.7);

        cur[pack(mnum,S,Q)] = 1;

        for (int i = pos; i < (int)dig.size(); i++) {
            nxt.clear();
            for (auto &kv : cur) {
                auto [mm, ss, qq] = unpack(kv.first);
                long long ways = kv.second;
                for (int d = 0; d <= 9; d++) {
                    int nm = (mm * 10 + d) % m;
                    int nS = (ss + d) % m;
                    int nQ = (qq + d*d) % m;
                    int key = pack(nm,nS,nQ);
                    long long &ref = nxt[key];
                    ref += ways;
                    if (ref >= MOD) ref -= MOD;
                }
            }
            swap(cur, nxt);
        }

        // check final condition for all states
        long long ans = 0;
        for (auto &kv : cur) {
            auto [mm, ss, qq] = unpack(kv.first);
            int rhs;
            if (m % 2 == 1) {
                int inv2 = (m + 1) / 2;
                rhs = ((ss * ss - qq + m) % m) * inv2 % m;
            } else {
                int val = (ss * ss - qq);
                val /= 2;
                rhs = ((val % m) + m) % m;
            }
            if (mm == rhs) {
                ans = (ans + kv.second) % MOD;
            }
        }
        return ans;
    } else {
        int lim = dig[pos];
        long long res = 0;
        for (int d = 0; d <= lim; d++) {
            int nm = (mnum * 10 + d) % m;
            int nS = (S + d) % m;
            int nQ = (Q + d*d) % m;
            res += go(pos+1, nm, nS, nQ, tight && (d==lim));
            if (res >= MOD) res -= MOD;
        }
        return res;
    }
}

long long solve(string s) {
    dig.clear();
    for (char c: s) dig.push_back(c-'0');
    return go(0,0,0,0,true);
}

// decrement string number by 1
string dec1(string s) {
    int i = s.size()-1;
    while (i>=0 && s[i]=='0') {
        s[i]='9';
        i--;
    }
    if (i>=0) s[i]--;
    else return "0";
    int p=0;
    while (p+1<(int)s.size() && s[p]=='0') p++;
    return s.substr(p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string L,R;
        cin >> L >> R >> m;
        string Lminus = dec1(L);
        long long ans = (solve(R) - solve(Lminus) + MOD) % MOD;
        cout << ans << "\n";
    }
}
