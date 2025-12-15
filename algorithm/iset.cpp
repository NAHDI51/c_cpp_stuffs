#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using vbb  = vector<vb>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using table = unordered_map<unsigned long, int>;
using pll = pair<ll,ll>;
using vpl = vector<pll>;
using vvpl = vector<vpl>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rof(i, n) for(int i = n-1; i >= 0   ; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define Flag cout << "Reached here.\n"

#define pb push_back
#define pbb pop_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 1000000005LL
#define MIN -MAX

#define lb(a, val) lower_bound(all(a), val);
#define ub(a, val) upper_bound(all(a), val);

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

#define mod 1000000007LL

//interval set.
//Most of the time the range is just as big as 1E18, thus I'll be using long long instead of int on the operations
class iset {
public:

set<pll> st;

iset() {
    st.ins({MAX,MAX}), st.ins({MIN,MIN});
}
iset(vpl& a) {
    st.ins({MAX,MAX}), st.ins({MIN,MIN});
    forn(i, a.sz()) ins(a[i]);

}

void ins(pll a) {
    auto one = upper_bound(all(st), pll{a.f, MAX});
    one--; 

    if(one->f <= a.f && a.s <= one->s) return;
    if(one->s >= a.f) a.f = one->f;

    auto two = upper_bound(all(st), pll{a.s, MAX});
    two--;

    if(one == two) {
        //only if it overlaps, and it is necessary to remove it.
        if(a.f <= one->f && one->s <= a.s) st.erase(one);
        st.ins(a);
        return;
    }
    if(two->f <= a.s) a.s = two->s;

    vector<set<pll>::iterator> rmv;

    for(auto i = one ; i != two; i++) rmv.pb(i);
    forn(i, rmv.sz()) {
        if(rmv[i]->f == MAX && rmv[i]->s == MAX) continue;
        if(rmv[i]->f == MIN && rmv[i]->s == MIN) continue;
        if(a.f <= rmv[i]->f && rmv[i]->s <= a.s) st.erase(rmv[i]);
    }
    st.ins(a);
}

void rmv(pll a) {
    auto one = upper_bound(all(st), pll{a.f, MAX});
    one--;

    //Compelte range.
    if(one->f <= a.f && a.s <= one->s) {
        auto onef = one->f, ones = one->s;
        auto p = pll{onef,a.f-1}, q = pll{a.s+1, ones};

        if(onef < a.f) st.ins(p);
        if(ones > a.s) st.ins(q);
        st.erase(one);
        return;
    }
    //Overlap
    if(one->f < a.f && one->s >= a.f) {
        auto p = pll{one->f, a.f-1};
        st.ins(pll{one->f, a.f-1});
    }

    auto two = upper_bound(all(st), pll{a.s, MAX});
    two--;
    if(one == two) {
        st.erase(one);
        return;
    }
    //Overlap
    if(two->s > a.s) {
        auto q = pll{a.s+1, two->s};
        st.ins(q);
    }

    vector<set<pll>::iterator> rmv;
    for(auto i = one; i != two; i++) rmv.pb(i);

    forn(i, rmv.sz()) {
        if(rmv[i]->f == MAX) continue;
        if(rmv[i]->s == MIN) continue;

        st.erase(rmv[i]);
    }

    //we already have inserted all the overlapping intervals, thus, in this case, just return.
}
void print() {
    for(auto i = st.begin(); i != st.end(); i++) {
        if(i->s == MIN || i->f == MAX) continue;
        cout << i->f << ' ' << i->s << '\n';
    }
    cout << '\n';
}
};

class RangeModule {
iset st;
public:
    RangeModule() {}
    
    void addRange(int left, int right) {
        st.ins(pll{left, right-1});
    }
    
    bool queryRange(int left, int right) {
        auto one = upper_bound(st.st.begin(), st.st.end(), pll{left,MAX});
        one--;
        return (one->f <= left) && ((right-1) <= one->s);
    }
    
    void removeRange(int left, int right) {
        st.rmv(pll{left, right-1});
    }
    void print() {
        st.print();
    }
    
};

int main() {
    RangeModule st;
    int n;
    cin >> n;
    forn(i, n) {
        int c;
        cin >> c;
        int a, b;
        cin >> a >> b;

        if(c == 1) {
            st.addRange(a,b);
        } 
        
        else if(c == 2) {
            st.removeRange(a,b);
        } 
        
        else {
            //cout << st.queryRange(a,b) << '\n';
        }
        st.print();
        //Flag;
    }
}