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



#define ways first
#define inv second

using pll = pair<long long,long long>;
using vi = vector<int>;

pll dp[16][2][2];
vi cnt_st;

pll solve(int pos, int started, int tight, vi &cnt, const string &s) {
    if(pos == -1) return {1,0}; // 1 way, 0 inversions

    pll &ret = dp[pos][started][tight];
    if(ret.ways != -1) return ret;

    ret = {0,0};

    int lim = tight ? (s[pos]-'0') : 9;

    for(int d = 0; d <= lim; d++) {
        int nstarted = started || d > 0;
        int ntight = tight && (d == lim);

        // count inversions caused by placing digit d
        int new_inv = 0;
        if(nstarted) {
            for(int k = 0; k < d; k++) new_inv += cnt[k];
        }

        // place digit d
        vi prev = cnt;
        if(nstarted) cnt[d]++;

        pll cur = solve(pos-1, nstarted, ntight, cnt, s);

        ret.ways += cur.ways;
        ret.inv += cur.inv + cur.ways * new_inv;

        cnt = prev; // backtrack
    }

    return ret;
}

long long F(long long num) {
    if(num < 0) return 0;
    string s = to_string(num);
    reverse(s.begin(), s.end()); // least significant digit at index 0
    cnt_st.assign(10,0);
    memset(dp,-1,sizeof(dp));
    return solve(s.size()-1,0,1,cnt_st,s).inv;
}

void solve_case() {
    long long l,r;
    cin >> l >> r;
    cout << F(r) - F(l-1) << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve_case();
    }
}